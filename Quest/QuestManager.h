#pragma once

#include <vector>

#include "Quest.h"
#include "QuestDataTable.h"

#include "../CommonDefines.h"

class CQuestManager
{	
public:
	CQuestManager();

	virtual ~CQuestManager();

	/** Create Quest Data table initialize other values **/
	/** ����Ʈ ���̺� �ε� �� ���� �ʱ�ȭ **/
	void Initialize();

	/*  Request/Receive player's quest list from server.
	network functionality is not implemented,
	but define functions to represent total process	*/
	/*  ��Ʈ��ũ ����� �����Ǿ� ������ ������,
		��ü ���μ����� ǥ���ϱ� ���� ������.	*/
	void RequestQuestList(int _usercode);
	void ReceiveQuestList(/*char* pMsg*/);

	/**	send updated status of player's quest	**/
	void SendUpdateQuest(int _usercode, int _qId);


	/**	Create CQuest with initial data using _id	**/
	CQuest CreateQuest(int _id);


	/**** Dev Option ****/
	/**** ���߿� �ʿ��� ��� ****/

	/** Print Quest Data table read from csv file **/
	/** CSV ���Ͽ��� �о���� ����Ʈ ������ ���̺� ��� **/
	void PrintQuestDataTable();


private:
	/** Data Table which hold all of information about existing quest **/
	/** ���� ���� �����ϴ� ��� ����Ʈ ������ ��� �ִ� ������ ���̺� **/
	CQuestDataTable QuestDataTable;
	
	/** List of Quests the player actually has **/
	/** ���� �÷��̾ �����ϰ� �ִ� ����Ʈ ���**/
	std::vector<CQuest> Vec_Quests;
	
};