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
	/** 퀘스트 테이블 로드 및 변수 초기화 **/
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
	/**** 개발에 필요한 기능 ****/

	/** Print Quest Data table read from csv file **/
	/** CSV 파일에서 읽어들인 퀘스트 데이터 테이블 출력 **/
	void PrintQuestDataTable();

	/** Display the list of quests player currently have **/
	/**	현재 보유하고 있는 퀘스트 목록 출력**/
	void PrintQuestList();


	/****	Sample Specified Function	****/

	/**	Save player class to user property from the player **/
	bool SetPlayer(CPlayer* player);

private:
	/** Data Table which hold all of information about existing quest **/
	/** 게임 내에 존재하는 모든 퀘스트 정보를 들고 있는 데이터 테이블 **/
	CQuestDataTable QuestDataTable;
	
	/** List of Quests the player actually has **/
	/** 실제 플레이어가 수행하고 있는 퀘스트 목록**/
	std::vector<CQuest> Vec_Quests;

	/** Read Quest save file(csv)**/
	bool ReadSavedFile(std::vector<sSavedQuestData>& vecQuestDataList, std::string strPath = SAVE_QUEST_DATA);

	/****	Sample Specified Variable	****/
	/**	Save player class to user property from the player **/
	CPlayer* Parent;
		
};