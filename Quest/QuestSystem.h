#pragma once

#include "QuestManager.h"

class CQuestSystem
{
private:
	class CQuestManager* m_questManager;

public:
	CQuestSystem();
	~CQuestSystem();

	/* inintialize quest manager */
	void Initialize();

	/**** Dev Option ****/
	void PrintQuestDataTable();

private:

	/** Check whether quest manager is available **/
	bool CheckManager();

};