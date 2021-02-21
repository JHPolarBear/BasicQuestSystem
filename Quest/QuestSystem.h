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

	/**	Load player's local saved quest data **/
	bool LoadLocalSavedData();


	/****	Sample Specified Function	****/
	/**	Save player class to user property from the player **/
	bool SetPlayer(CPlayer* player);

	/**** Dev Option ****/

	/** Print Quest Data table read from csv file **/
	/** CSV ���Ͽ��� �о���� ����Ʈ ������ ���̺� ��� **/
	void PrintQuestDataTable();

	/** Display the list of quests player currently have **/
	/**	���� �����ϰ� �ִ� ����Ʈ ��� ���**/
	void PrintQuestList();

private:

	/** Check whether quest manager is available **/
	bool CheckManager();

};