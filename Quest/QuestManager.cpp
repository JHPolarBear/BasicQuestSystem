
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
		FUNC_LOG("Failed to Read Data Table");
	}

	Vec_Quests.clear();
}

bool CQuestManager::LoadLocalSavedData()
{
	std::vector<sQuestLoadData> vecQuestDataList;

	//Read Saved File
	if(ReadSavedFile(vecQuestDataList) == false)
	{
		FUNC_LOG("Failed to Read Save File");
		return false;
	}

	// Create Quest Data from parsed data list
	for(int i=0; i < vecQuestDataList.size(); i++)
	{
		bool bLoad = false;

		CQuest quest = CreateQuest(vecQuestDataList[i].questId);

		// Check valid quest id
		if(quest.GetId() != INVALID_QUEST_ID)
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

E_ASSIGN_QUEST CQuestManager::AssignQuest(int _id)
{
	// Check if player already have the same quest.
	if(IsQuestExist(_id) == true)
	{
		FUNC_LOG("Quest id %d is already exists", _id);
		return E_ASSIGN_QUEST::ALREAD_EXIST;
	}

	CQuest newQuest = CreateQuest(_id);

	if(newQuest.GetId() == INVALID_QUEST_ID)
	{
		FUNC_LOG("Faild to create Quest %d", _id);
		return E_ASSIGN_QUEST::FAIL_ON_CREATION;
	}

	// Change quest state in progress
	newQuest.SetState(E_QUEST_STATE::ACTIVE);

	Vec_Quests.push_back(newQuest);

	return E_ASSIGN_QUEST::SUCCESS;
}

void CQuestManager::UpdateQuest(sQuestUpdateData sData)
{
	vector<CQuest>::iterator _iter = Vec_Quests.begin();

	// Update all of the quest that manager has
	while (_iter != Vec_Quests.end())
	{
		(*_iter).Update(sData);

		_iter++;
	}

	_iter = Vec_Quests.begin();
	for(_iter; _iter != Vec_Quests.end();)
	{
		// show result and delete from the list if the quest succeeded after update
		if((*_iter).GetState() == E_QUEST_STATE::SUCCESS)
		{
			// Show the result of the quest
			FUNC_LOG("Complete Quest \"%s\", Quest ID: %d", (*_iter).GetTitle().c_str(), (*_iter).GetId());

			int nextQuestID = INVALID_QUEST_ID;

			// get the following quest if exists
			if((*_iter).GetFollowQuestId() != 0)
			{
				nextQuestID = (*_iter).GetFollowQuestId();
				
			}

			// delete from the list
			// consider moving succeeded quest to separate list that manages the completed quests.
			_iter = Vec_Quests.erase(_iter);

			// create next quest if exists
			if(nextQuestID != INVALID_QUEST_ID)
			{
				CQuest nextQuest = CreateQuest(nextQuestID);

				if (nextQuest.GetId() != INVALID_QUEST_ID)
				{
					nextQuest.SetState(E_QUEST_STATE::ACTIVE);

					Vec_Quests.push_back(nextQuest);

					FUNC_LOG("Create following quest \"%s\" (Quest ID: %d)", nextQuest.GetTitle().c_str(), nextQuest.GetId());
				}			
			}		
		}
		else
		{
			_iter++;
		}
	}

	
	for(int i=0; i<Vec_Quests.size(); i++)
	{
		Vec_Quests[i].Update(sData);

		// show result and delete from the list if the quest succeeded after update
		if(Vec_Quests[i].GetState() == E_QUEST_STATE::SUCCESS)
		{
			
		}
	}

	

}

bool CQuestManager::IsQuestExist(int _id)
{
	bool bFind = false;

	for(int i=0; i< Vec_Quests.size(); i++)
	{
		if (Vec_Quests[i].GetId() == _id)
		{
			bFind = true;
			break;
		}
	}

	return bFind;
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
		cout << "Quest No." << i+1 << endl;
		Vec_Quests[i].PrintQuest();
	}
}

/**	Save player class to user property from the player **/
bool CQuestManager::SetPlayer(CPlayer* player)
{
	if (player == nullptr)
	{
		FUNC_LOG(" Player not exists");
		return false;
	}
	else
	{
		Parent = player;

		return true;
	}
}

bool CQuestManager::ReadSavedFile(std::vector<sQuestLoadData>& vecQuestDataList, std::string strPath /*= SAVED_QUEST_DATA*/)
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
		sQuestLoadData saveData;

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
			FUNC_LOG(" Failed To Create Quest Data: Task size mismatch");
			continue;
		}

		saveData.vec_Task_Ids = Vec_Task_Ids;
		saveData.vec_Task_Vals = Vec_Task_Vals;

		vecQuestDataList.push_back(saveData);
	}

	return true;
}
