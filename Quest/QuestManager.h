#pragma once

#include <vector>

#include "Quest.h"
#include "QuestDataTable.h"

#include "../CommonDefines.h"

class CPlayer;

class CQuestManager
{	
public:
	CQuestManager();

	virtual ~CQuestManager();

	/** Create Quest Data table initialize other values **/
	/** ����Ʈ ���̺� �ε� �� ���� �ʱ�ȭ **/
	void Initialize();

	/**	Load player's local saved quest data **/
	bool LoadLocalSavedData();
	
	/**	Create CQuest with initial data using _id	**/
	CQuest CreateQuest(int _id);

	/** Create new quest and assign to manager	**/
	E_ASSIGN_QUEST AssignQuest(int _id);

	/**	Update quest **/
	void UpdateQuest(E_EVENT_LISTENER_TYPE etype, sEventListener_Info sInfo);

	/** return true if player have quest with id '_id' **/
	bool IsQuestExist(int _id);
	
	
	/**** Dev Option ****/
	/**** ���߿� �ʿ��� ��� ****/

	/** Print Quest Data table read from csv file **/
	/** CSV ���Ͽ��� �о���� ����Ʈ ������ ���̺� ��� **/
	void PrintQuestDataTable();

	/** Display the list of quests player currently have **/
	/**	���� �����ϰ� �ִ� ����Ʈ ��� ���**/
	void PrintQuestList();


	/****	Sample Specified Function	****/

	/**	Save player class to user property from the player **/
	bool SetPlayer(CPlayer* player);

private:
	/** Data Table which hold all of information about existing quest **/
	/** ���� ���� �����ϴ� ��� ����Ʈ ������ ��� �ִ� ������ ���̺� **/
	CQuestDataTable QuestDataTable;
	
	/** List of Quests the player actually has **/
	/** ���� �÷��̾ �����ϰ� �ִ� ����Ʈ ���**/
	std::vector<CQuest> Vec_Quests;

	/** Read Quest save file(csv)**/
	bool ReadSavedFile(std::vector<sSavedQuestData>& vecQuestDataList, std::string strPath = SAVE_QUEST_DATA);

	/****	Sample Specified Variable	****/
	/**	Save player class to user property from the player **/
	CPlayer* Parent;
		
};