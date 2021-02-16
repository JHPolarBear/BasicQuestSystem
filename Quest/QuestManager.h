#pragma once

#include <vector>

#include "Quest.h"
#include "QuestDataTable.h"

class CQuestManager
{	
public:
	CQuestManager();

	virtual ~CQuestManager();

	/** Create Quest Data table initialize other values **/
	/** 퀘스트 테이블 로드 및 변수 초기화 **/
	void Initialize();


	/**** Dev Option ****/
	/**** 개발에 필요한 기능 ****/

	/** Print Quest Data table read from csv file **/
	/** CSV 파일에서 읽어들인 퀘스트 데이터 테이블 출력 **/
	void PrintQuestDataTable();


private:
	/** Data Table which hold all of information about existing quest **/
	/** 게임 내에 존재하는 모든 퀘스트 정보를 들고 있는 데이터 테이블 **/
	CQuestDataTable QuestDataTable;
	
	/** List of Quests the player actually has **/
	/** 실제 플레이어가 수행하고 있는 퀘스트 목록**/
	std::vector<CQuest> Vec_Quests;
	
};