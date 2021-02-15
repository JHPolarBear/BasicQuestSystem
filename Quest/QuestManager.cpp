
#include <iostream>

#include "../csv/csv.h"

#include "QuestDefines.h"
#include "QuestManager.h"

#include "Task/Task.h"

#include "../Util/StringUtility.h"

using namespace std;


CQuestManager::CQuestManager()
{

}

CQuestManager::~CQuestManager()
{
}

void CQuestManager::Initialize()
{
	if(ReadDataTable() == false)
	{
		cout << "[" << __FUNCTION__ << "] Failed to Read Data Table" << endl;
		return;
	}
}

void CQuestManager::PrintQuestDataTable()
{
	for(int i=0; i<Vec_Quests.size(); i++)
	{
		Vec_Quests[i].PrintInfo();
	}
}

bool CQuestManager::ReadDataTable()
{
	// <count> means number of columns in data table 
	io::CSVReader<9> in("Quest/Quest_Table.csv");

	in.read_header(io::ignore_extra_column, "ID", "TITLE", "TASK_ACTS", "TASK_TGTS", "TASK_CNTS",\
					"REWARD_IDS", "REWARD_CNTS","PRECEDE_QID","FOLLOW_QID");

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
		CQuest NewQuest;

		NewQuest.SetId(quest_id);
		NewQuest.SetTitle(quest_title);

		NewQuest.SetPrecedeQuestId(PrecedeQId);
		NewQuest.SetFollowQuestId(FollowQId);
		
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
		if(Vec_Task_Actions.size() != Vec_Task_Counts.size() || Vec_Task_Actions.size() != Vec_Task_Targets.size())
		{
			cout << __FUNCTION__ << "Quest Id: " << quest_id << "Task information Size not match" << endl;
			continue;
		}

		// Check if all elements of the reward are the same size
		if(Vec_Reward_Ids.size() != Vec_Reward_Counts.size())
		{
			cout << __FUNCTION__ << "Quest Id: " << quest_id << "Reward information Size not match" << endl;
			continue;
		}


		// create task and save into the quest
		vector<CTask> vecNewTasks;

		for(int i=0; i<Vec_Task_Actions.size(); i++)
		{
			sTaskInfo NewTaskInfo(Vec_Task_Actions[i], Vec_Task_Targets[i], Vec_Task_Counts[i]);
			
			CTask NewTask(NewTaskInfo, i);

			vecNewTasks.push_back(NewTask);
		}
		NewQuest.SetVecTasks(vecNewTasks);


		// create reward list and save into quest
		vector<sReward> vecNewRewards;

		for (int i = 0; i < Vec_Reward_Ids.size(); i++)
		{
			sReward NewReward(Vec_Reward_Ids[i], Vec_Reward_Counts[i]);

			vecNewRewards.push_back(NewReward);
		}
		NewQuest.SetRewards(vecNewRewards);
		
		// Save Quest into the vector
		Vec_Quests.push_back(NewQuest);
	}

	return true;
}
