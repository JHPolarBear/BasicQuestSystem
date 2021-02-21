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

	//	Test Code - Print quest list player load
	player.PrintQuestList();
	
	system("pause");

	return 0;
}