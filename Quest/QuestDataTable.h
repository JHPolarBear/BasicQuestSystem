#pragma once

#include <map>

#include "QuestDefines.h"

class CQuest;

/** Class To save Quest Raw Information **/
/** 퀘스트 정보를 저장하기 위한 클래스 **/
class CQuestData {

public:
	CQuestData();
	virtual ~CQuestData();

	// Print Basic information about the quest itself
	void PrintQuestData();

private:
	/** Quest ID - Every Quest has unique ID **/
	/** 퀘스트 ID - 모든 퀘스트는 고유한 ID를 보유 **/
	int Id;

	/** Title of the quest **/
	/** 퀘스트 제목 **/
	std::string Title;

	/** List of tasks to be accomplished to complete quest **/
	/**	퀘스트를 달성하기 위해 수행해야 하는 작업들 **/
	std::vector<sTaskData> Vec_TaskDatas;

	/** List of Rewards given when quest is done **/
	/**	퀘스트를 완료 시 주어지는 보상들의 목록 **/
	std::vector<sReward> Vec_Rewards;

	/** Quest that must precede the current quest 
		0 if precede quest not exists		**/		
	/**	현재 퀘스트의 선행 퀘스트 ID
		만약 선행 퀘스트가 없는 경우 0으로 세팅 **/
	int Precede_Quest_Id;

	/** Quests that must follow the current quest
		0 if following quest not exists		**/			
	/**	현재 퀘스트 완료 시 다음으로 이어지는 퀘스트 ID
		만약 다음 퀘스트가 없는 경우 0으로 세팅 **/
	int Follow_Quest_Id;


public:
	/****	Getter && Setter	****/
	void			SetId(int _id) { Id = _id; }
	int				GetId() { return Id; }

	void			SetTitle(std::string _title) { Title = _title; }
	std::string		GetTitle() { return Title; }

	void			SetPrecedeQuestId(int _precedId) { Precede_Quest_Id = _precedId; }
	int				GetPrecedeQuestId() { return Precede_Quest_Id; }

	void			SetFollowQuestId(int _followId) { Follow_Quest_Id = _followId; }
	int				GetFollowQuestId() { return Follow_Quest_Id; }

	void				SetVecTaskDatas(std::vector<sTaskData> _vec_taskdatas) { Vec_TaskDatas = _vec_taskdatas; }
	std::vector<sTaskData>	GetVecTaskDatas() { return Vec_TaskDatas; }

	void					SetRewards(std::vector<sReward> _vec_rewards) { Vec_Rewards = _vec_rewards; }
	std::vector<sReward>	GetRewards() { return Vec_Rewards; }
};

/** Map to manage all Quest Data in the game **/
/** 게임 내에 존재하는 모든 Quest Data를 관리하기 위한 Map **/
typedef std::map<int, CQuestData> QUEST_DATA_TABLE;

/** Class to manage all Quest Data in the game **/
/** 게임 내에 존재하는 모든 Quest Data를 관리하기 위한 클래스 **/
class CQuestDataTable
{
public:
	CQuestDataTable();
	virtual ~CQuestDataTable();

private:
	/** Quest Data Table
		[Param] QId: Unique Quest Id  / QData: Quest Information
		Save Quest Data table with std::map to accelerate search speed	 **/	
	/**	검색 속도를 높이기 위해 std::map을 사용하여 저장	 **/
	QUEST_DATA_TABLE Quest_Data_Map;

public:

	// Read Qeust Data Table From csv
	// CSV 파일에서 퀘스트 데이터 테이블을 읽어들임
	bool	ReadDataTable();

	// return CQuestData matched to qid
	CQuestData GetQuestData(int _qid);

	CQuest	CreateQuest(int _qid);

	/**** Dev Option ****/
	/**** 개발에 필요한 기능 ****/

	// Print Quest Data table read from csv file
	// CSV 파일에서 읽어들인 퀘스트 데이터 테이블 출력
	void PrintQuestDataTable();
};