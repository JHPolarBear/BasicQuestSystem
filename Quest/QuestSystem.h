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

	/*  Request/Receive player's quest list from server.
		network functionality is not implemented, 
	    but define functions to represent total process	*/
	/*  네트워크 기능이 구현되어 있지는 않지만,
		전체 프로세스를 표현하기 위해 정의함.	*/
	void RequestQuestList(int _usercode);
	void ReceiveQuestList(/*char* pMsg*/);

	void SendUpdateQuest(int _usercode, int _qId);
	

	/**** Dev Option ****/
	void PrintQuestDataTable();

private:

	/** Check whether quest manager is available **/
	bool CheckManager();

};