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
	/*  ��Ʈ��ũ ����� �����Ǿ� ������ ������,
		��ü ���μ����� ǥ���ϱ� ���� ������.	*/
	void RequestQuestList(int _usercode);
	void ReceiveQuestList(/*char* pMsg*/);

	void SendUpdateQuest(int _usercode, int _qId);
	

	/**** Dev Option ****/
	void PrintQuestDataTable();

private:

	/** Check whether quest manager is available **/
	bool CheckManager();

};