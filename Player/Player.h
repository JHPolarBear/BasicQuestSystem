#pragma once

#include "../Quest/QuestSystem.h"

#include "../CommonDefines.h"

class CPlayer : public Subject
{
public:

	CPlayer();
	CPlayer(int usercode);
	virtual ~CPlayer();

private:

	/*	Player's unique Id	*/
	int UserCode;

	/* Manage player quest list*/
	static CQuestSystem* QuestSystem;

public:
	/****	Getter && Setter	****/
	void			SetUserCode(int _id) { UserCode = _id; }
	int				GetUserCode() { return UserCode; }

	/**	Load player's local saved data **/
	bool LoadLocalSavedData();

	/**	assign quest with Quest ID(_qid) to player**/
	E_ASSIGN_QUEST AssignQuest(int _qid);

	/**** Dev Option ****/

	/**	Print player's quest list	**/
	void PrintQuestList();

};