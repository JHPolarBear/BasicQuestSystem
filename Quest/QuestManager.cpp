
#include <iostream>

#include "../csv/csv.h"

#include "QuestDefines.h"
#include "QuestManager.h"

#include "Task/Task.h"

#include "../Util/StringUtility.h"

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

// Print Quest Data table read from csv file
// CSV 파일에서 읽어들인 퀘스트 데이터 테이블 출력
void CQuestManager::PrintQuestDataTable()
{
	QuestDataTable.PrintQuestDataTable();
}
