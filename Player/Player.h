#pragma once

#include "../Quest/QuestSystem.h"

class CPlayer{
public:

	CPlayer();
	CPlayer(int usercode);
	virtual ~CPlayer();

private:

	/*	Player's unique Id	*/
	int UserCode;

	/* Manage player quest list*/
	CQuestSystem QuestSystem;

public:
	/****	Getter && Setter	****/
	void			SetUserCode(int _id) { UserCode = _id; }
	int				GetUserCode() { return UserCode; }

	/**	Load player's local saved data **/
	bool LoadLocalSavedData();

	void PrintQuestList();

};