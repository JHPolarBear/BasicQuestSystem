#pragma once

#include <vector>

#include "Quest.h"

class CQuestManager
{	
public:
	CQuestManager();

	~CQuestManager();

	/** Create Quest Data table initialize other values **/
	void Initialize();


	/**** Dev Option ****/

	// Print Quest Data table read from csv file
	void PrintQuestDataTable();

private:

	// Read Qeust Data Table From csv
	bool	ReadDataTable();

private:
	
	// List of Quests the player has
	std::vector<CQuest> Vec_Quests;
	
};