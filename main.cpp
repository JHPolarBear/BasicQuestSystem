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
	//	player.PrintQuestList();

	//	Sample code - player notify event to all listener using notify function ( i.e) QuestSystem )
	sEventListener_Info sInfo;
	player.Notify(E_EVENT_LISTENER_PLAYER_HUNT, sInfo);
	
	system("pause");

	return 0;
}