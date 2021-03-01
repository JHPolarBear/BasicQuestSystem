#include <iostream>
#include <string>

#include "Quest/QuestSystem.h"
#include "Player/Player.h"

#include "CommonDefines.h"

using namespace std;

// Sample Program to show how quest system works
int main()
{
	// Create player with usercode 1234
	CPlayer player(1234);

	//	Test Code - Print quest data table read form csv file
	//	QuestSystem.PrintQuestDataTable();

	//	Load local save file from csv
	player.LoadLocalSavedData();

	// Sample code - assign new quest to player
	player.AssignQuest(103);

	//	Test Code - Print quest list player load
	//player.PrintQuestList();

	//	Sample code - player notify event to all listener using notify function ( i.e) QuestSystem )
	//	Expect that player hunt a wolf

	system("pause");
	cout << endl;

	// Create event
	CEventListener_Info_Quest* sInfo = new CEventListener_Info_Quest();
	sInfo->SetTarget(E_TASK_TARGET::MON_WOLF);
	sInfo->SetTargetCnt(1.f);
	sInfo->SetTargetCntType(E_TASK_TARGET_CNT_TYPE::APPEND);

	// notify event to quest system
	player.Notify(E_EVENT_LISTENER_PLAYER_HUNT, sInfo);

	//	Test Code - Print quest list player load after update
	//player.PrintQuestList();

	// Sample code - TODO: implement saving current quest data for player in csv file
	
	system("pause");

	return 0;
}