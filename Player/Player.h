#pragma once

#include "../Quest/QuestSystem.h"

class CPlayer{
public:

	CPlayer();
	virtual ~CPlayer();

private:

	/*	Player's unique Id	*/
	int UserCode;

	/* Manage player quest list*/
	CQuestSystem QuestSystem;


};