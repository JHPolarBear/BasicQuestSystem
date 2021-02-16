
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
// CSV ���Ͽ��� �о���� ����Ʈ ������ ���̺� ���
void CQuestManager::PrintQuestDataTable()
{
	QuestDataTable.PrintQuestDataTable();
}
