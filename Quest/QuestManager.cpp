
#include <iostream>

#include "../csv/csv.h"

#include "QuestDefines.h"
#include "QuestManager.h"

#include "Task/Task.h"

#include "../Player/Player.h"

#include "../CommonDefines.h"

using namespace std;

CQuestManager::CQuestManager()
{
	Initialize();
}

CQuestManager::~CQuestManager()
{
}

void CQuestManager::Initialize()
{
	//Create QuestDataTable and read the table from csv
	if (QuestDataTable.ReadDataTable() == false)
	{
		cout << "[" << __FUNCTION__ << "] Failed to Read Data Table" << endl;
	}

	Vec_Quests.clear();
}

bool CQuestManager::LoadLocalSavedData()
{
	std::vector<sSavedQuestData> vecQuestDataList;

	//Read Saved File
	if(ReadSavedFile(vecQuestDataList) == false)
	{
		cout << __FUNCTION__ << "Failed to Read Save File" << endl;
		return false;
	}

	// Create Quest Data from parsed data list
	for(int i=0; i < vecQuestDataList.size(); i++)
	{
		bool bLoad = false;

		CQuest quest = CreateQuest(vecQuestDataList[i].questId);

		// Check valid quest id
		if(quest.GetId() != 0)
		{		
			// Restor saved data
			bLoad = quest.RestoreSavedDatas(vecQuestDataList[i]);
		}

		// Save quest data if both creating quest and restoring data are success
		if(bLoad)
		{
			Vec_Quests.push_back(quest);
		}
	}

	return true;
}

CQuest CQuestManager::CreateQuest(int _id)
{
	CQuest quest;
	return QuestDataTable.CreateQuest(_id);
}

// Print Quest Data table read from csv file
// CSV 파일에서 읽어들인 퀘스트 데이터 테이블 출력
void CQuestManager::PrintQuestDataTable()
{
	QuestDataTable.PrintQuestDataTable();
}

/** Display the list of quests player currently have **/
/**	현재 보유하고 있는 퀘스트 목록 출력**/
void CQuestManager::PrintQuestList()
{
	for(int i=0; i<Vec_Quests.size(); i++)
	{
		cout << "Quest No." << i << endl;
		Vec_Quests[i].PrintQuest();
	}
}

/**	Save player class to user property from the player **/
bool CQuestManager::SetPlayer(CPlayer* player)
{
	if(player == nullptr)
		cout << __FUNCTION__ << " Player not exists" << endl ;
	else
	{
		Parent = player;

		return true;
	}
}

bool CQuestManager::ReadSavedFile(std::vector<sSavedQuestData>& vecQuestDataList, std::string strPath /*= SAVE_QUEST_DATA*/)
{
	// <count> means number of columns in data table 
	io::CSVReader<4> in(strPath.c_str());

	in.read_header(io::ignore_extra_column, "USERCODE", "QID", "TASK_IDS", "TASK_VALS");

	// player's usercode
	int usercode = 0;

	int qId = 0;

	string tasks_ids;

	string tasks_vals;

	while (in.read_row(usercode, qId, tasks_ids, tasks_vals)	)
	{
		sSavedQuestData saveData;

		// pass if usercode saved in file is not equal to current player's usercode.
		if(usercode != Parent->GetUserCode())
		{
			continue;
		}
		
		//	Parse Save data and save in to Quest Data list
		saveData.questId = qId;

		vector<int> Vec_Task_Ids;

		vector<float> Vec_Task_Vals;

		Vec_Task_Ids = Util::DivideStringToVectorInt(tasks_ids, ' ');
		Vec_Task_Vals = Util::DivideStringToVectorFloat(tasks_vals, ' ');

		// Check both size of Task_Ids and Task_Vals are equal
		if(Vec_Task_Ids.size() != Vec_Task_Vals.size())
		{
			cout << __FUNCTION__ << " Failed To Create Quest Data: Task size mismatch" << endl;
			continue;
		}

		saveData.vec_Task_Ids = Vec_Task_Ids;
		saveData.vec_Task_Vals = Vec_Task_Vals;

		vecQuestDataList.push_back(saveData);
	}

	return true;
}
