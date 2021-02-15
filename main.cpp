#include <iostream>
#include <string>

#include "Quest/QuestSystem.h"

using namespace std;

// Sample Program to show how quest system works
int main()
{
	// Assume that main function act as 
	CQuestSystem QuestSystem;

	// Initialize QuestSystem;
	QuestSystem.Initialize();

	// Test - Print quest data table read form csv file
	QuestSystem.PrintQuestDataTable();
	
	system("pause");

	return 0;
}