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
	   
	/**** Dev Option ****/
	/**** ���߿� �ʿ��� ��� ****/

	/** Print Quest Data table read from csv file **/
	/** CSV ���Ͽ��� �о���� ����Ʈ ������ ���̺� ��� **/
	void PrintQuestDataTable();
	
	/**	Create CQuest with initial data using _id	**/
	CQuest CreateQuest(int _id);


private:
	/** Data Table which hold all of information about existing quest **/
	/** ���� ���� �����ϴ� ��� ����Ʈ ������ ��� �ִ� ������ ���̺� **/
	CQuestDataTable QuestDataTable;
	
	/** List of Quests the player actually has **/
	/** ���� �÷��̾ �����ϰ� �ִ� ����Ʈ ���**/
	std::vector<CQuest> Vec_Quests;
	
};