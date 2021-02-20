#include <iostream>

#include "../csv/csv.h"

#include "QuestDataTable.h"
#include "Quest.h"

#include "../Util/StringUtility.h"

using namespace std;


CQuestData::CQuestData()
{

}

CQuestData::~CQuestData()
{

}

void CQuestData::PrintQuestData()
{
	cout << "[Quest ID: " << GetId() << " / Quest Title: " << GetTitle() << " ]" << endl;
	cout << "[Precede Quest ID: " << GetPrecedeQuestId() << " / Follow Quest ID: " << GetFollowQuestId() << " ]" << endl;

	std::vector<sTaskData> _vecTaskData = GetVecTaskDatas();
	for (int i = 0; i < _vecTaskData.size(); i++)
	{
		sTaskData _data = _vecTaskData[i];
		cout << "[Task " << i << ": Task_Action: " << _data.action <<
			" / Task_Target: " << _data.target << " / Task_Count: " << _data.targetCount << " ]" << endl;
	}

	std::vector<sReward> _vecReward = GetRewards();
	for (int i = 0; i < _vecReward.size(); i++)
	{
		sReward _reward = _vecReward[i];
		cout << "[Reward " << i << ": Reward_ID: " << _reward.Id << " / Reward_Count: " << _reward.Count << " ]" << endl;
	}

	cout << endl << endl;
}


CQuestDataTable::CQuestDataTable()
{
	Quest_Data_Map.clear();
}

CQuestDataTable::~CQuestDataTable()
{

}

bool CQuestDataTable::ReadDataTable()
{
	// <count> means number of columns in data table 
	io::CSVReader<9> in(BASE_QUEST_DATASET);

	in.read_header(io::ignore_extra_column, "ID", "TITLE", "TASK_ACTS", "TASK_TGTS", "TASK_CNTS", \
		"REWARD_IDS", "REWARD_CNTS", "PRECEDE_QID", "FOLLOW_QID");

	// Quest Id
	int quest_id;

	string quest_title;

	// Task's information
	// Task could be more than one, and if task is more than one, 
	// values are saved in form of list distinguished by a space

	// Action types for each task
	// read as string and save the values into TASK_ACTION type
	string task_acts;

	// Action targets for each task
	string task_tgts;

	// counts to accomplish each task
	string task_cnts;

	// item id for reward
	string reward_ids;

	// reward count
	string reward_cnts;

	// precede Quest Id
	int PrecedeQId;

	// follow Quest Id
	int FollowQId;

	while (in.read_row(quest_id, quest_title, task_acts, task_tgts, task_cnts, reward_ids, reward_cnts, PrecedeQId, FollowQId))
	{
		CQuestData NewQuestData;

		NewQuestData.SetId(quest_id);
		NewQuestData.SetTitle(quest_title);

		NewQuestData.SetPrecedeQuestId(PrecedeQId);
		NewQuestData.SetFollowQuestId(FollowQId);

		// List of task information
		vector<int> Vec_Task_Actions;
		vector<int> Vec_Task_Targets;
		vector<float> Vec_Task_Counts;

		// List of reward information
		vector<int> Vec_Reward_Ids;
		vector<int> Vec_Reward_Counts;

		// Save each elements value into vector
		Vec_Task_Actions = Util::DivideStringToVectorInt(task_acts, ' ');
		Vec_Task_Targets = Util::DivideStringToVectorInt(task_tgts, ' ');
		Vec_Task_Counts = Util::DivideStringToVectorFloat(task_cnts, ' ');

		Vec_Reward_Ids = Util::DivideStringToVectorInt(reward_ids, ' ');
		Vec_Reward_Counts = Util::DivideStringToVectorInt(reward_cnts, ' ');

		// Check if all elements of the task are the same size
		if (Vec_Task_Actions.size() != Vec_Task_Counts.size() || Vec_Task_Actions.size() != Vec_Task_Targets.size())
		{
			cout << __FUNCTION__ << "Quest Id: " << quest_id << "Task information Size not match" << endl;
			continue;
		}

		// Check if all elements of the reward are the same size
		if (Vec_Reward_Ids.size() != Vec_Reward_Counts.size())
		{
			cout << __FUNCTION__ << "Quest Id: " << quest_id << "Reward information Size not match" << endl;
			continue;
		}


		// create task and save into the quest
		vector<sTaskData> vecTaskDatas;

		for (int i = 0; i < Vec_Task_Actions.size(); i++)
		{
			sTaskData NewTaskData(Vec_Task_Actions[i], Vec_Task_Targets[i], Vec_Task_Counts[i]);

			vecTaskDatas.push_back(NewTaskData);
		}
		NewQuestData.SetVecTaskDatas(vecTaskDatas);


		// create reward list and save into quest
		vector<sReward> vecNewRewards;

		for (int i = 0; i < Vec_Reward_Ids.size(); i++)
		{
			sReward NewReward(Vec_Reward_Ids[i], Vec_Reward_Counts[i]);

			vecNewRewards.push_back(NewReward);
		}
		NewQuestData.SetRewards(vecNewRewards);

		// Save Quest into the vector
		Quest_Data_Map.insert(std::make_pair(quest_id, NewQuestData));
	}

	return true;
}

CQuestData CQuestDataTable::GetQuestData(int _qid)
{
	QUEST_DATA_TABLE::iterator _iter = Quest_Data_Map.find(_qid);

	if(_iter != Quest_Data_Map.end())
	{
		return _iter->second;
	}
	else
	{
		cout << "[" << __FUNCTION__ << "] Failed to find Quest Data - QID: " << _qid << endl; 

		CQuestData _Dummy;
		return _Dummy;
	}
}
// Create CQuest with initial data using _id
CQuest CQuestDataTable::CreateQuest(int _qid)
{
	CQuest quest;

	CQuestData questData = GetQuestData(_qid);

	// Copy quest base info if fine quest matched to _qid
	if(questData.GetId() == _qid)
	{
		quest.SetId(questData.GetId());
		quest.SetTitle(questData.GetTitle());

		quest.SetPrecedeQuestId(questData.GetPrecedeQuestId());
		quest.SetFollowQuestId(questData.GetFollowQuestId());
	}

	return quest;
}

void CQuestDataTable::PrintQuestDataTable()
{
	QUEST_DATA_TABLE::iterator _iter = Quest_Data_Map.begin();

	while(_iter != Quest_Data_Map.end())
	{
		(_iter->second).PrintQuestData();
		_iter++;
	}
}

