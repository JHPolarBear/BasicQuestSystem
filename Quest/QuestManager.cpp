
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

void CQuestManager::RequestQuestList(int _usercode)
{
	// Psuedo code

	// Add nUsercode to packet
	sPktCTOSRequestQuestList sQuestRequest;

	sQuestRequest.usercode = _usercode;

	// Send packet to server to request players's quest list

	// Send sQuestRequest
}

void CQuestManager::ReceiveQuestList(/*char* pMsg*/)
{
	// Assume that client receive sPktStoCRequestQuestList packet
	sPktStoCRequestQuestList sQuestList;

	//sQuestList = pMsg -> get sPktStoCRequestQuestList packet

	// Check usercode

	// Parse quest data 
	for(int i=0; i< sQuestList.questCnt; i++)
	{
		sNetQuestInfo sQuestInfo;

		// sQuestInfo -> get sQuestInfo from packet

		CQuest recvQuest = CreateQuest(sQuestInfo.questId);		
	}
}

void CQuestManager::SendUpdateQuest(int _usercode, int _qId)
{

}

CQuest CQuestManager::CreateQuest(int _id)
{
	CQuest quest;
	return quest;
	//return QuestDataTable.CreateQuest(_id);
}

// Print Quest Data table read from csv file
// CSV 파일에서 읽어들인 퀘스트 데이터 테이블 출력
void CQuestManager::PrintQuestDataTable()
{
	QuestDataTable.PrintQuestDataTable();
}
