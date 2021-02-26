#pragma once

#include "QuestManager.h"
#include "../CommonDefines.h"

class CQuestSystem : public Observer
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

	E_ASSIGN_QUEST AssignQuest(int _qid);


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

	/** Observer class override **/
	void onNotify(E_EVENT_LISTENER_TYPE etype, CEventListener_Info_Base* sInfo) override;

private:

	/** Check whether quest manager is available **/
	bool CheckManager();

	/** Change Event Listener type to quest's task action **/
	E_TASK_ACTION ConvertEventTypeToTaskAction(E_EVENT_LISTENER_TYPE eType);

};