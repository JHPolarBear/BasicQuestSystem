#pragma once

#include <vector>

#include "Task/Task.h"
#include "QuestDefines.h"

/** Quest class used to handle actual player quest lists
	Inherit CQuestData and add State value to control quest process **/
/** 실제 플레이어가 수행중인 퀘스트를 관리하기 위한 클래스
	CQuestData를 상속 받아 State 값을 추가하여 사용					**/
class CQuest
{
public:
	CQuest();
	virtual ~CQuest();

private:

	/** Quest ID - Every Quest has unique ID **/
	/** 퀘스트 ID - 모든 퀘스트는 고유한 ID를 보유 **/
	int Id;

	/** Title of the quest **/
	/** 퀘스트 제목 **/
	std::string Title;

	/**	List of tasks that should be done to accomplish the quest**/
	/**	퀘스트를 달성하기 위해 수행해야 하는 작업들 **/
	std::vector<CTask> Vec_Tasks;

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
	
	/** Event state **/
	/** 이벤트 스테이트 **/
	E_QUEST_STATE State;

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

	void			SetState(E_QUEST_STATE _state)	{State = _state;}
	E_QUEST_STATE		GetState()				{return State;}

	void			SetVecTasks(std::vector<CTask> _vec_tasks)	{Vec_Tasks = _vec_tasks;}
	const std::vector<CTask>	GetVecTasks()					{return Vec_Tasks;}

	void					SetRewards(std::vector<sReward> _vec_rewards) { Vec_Rewards = _vec_rewards; }
	std::vector<sReward>	GetRewards() { return Vec_Rewards; }


	/****	Function	****/

	/**	Set saved value to quest tasks
		Param vecSavedTaskVal: saved quest data previously performed by the player	**/
	/**	저장된 퀘스트 데이터를 바탕으로 퀘스트 Task 및 이벤트 상태를 복구
		Param vecSavedTaskVal: 이전에 플레이어가 수행한 퀘스트 정보	**/
	bool		RestoreSavedDatas(sQuestLoadData savdData);
	 
	/** Update Quest - udate all tasks and quest state according to the state of all tasks **/
	/** 퀘스트 업데이트 - Task 결과를 업데이트 한 후, 결과에 따라 Task 및 퀘스트의 상태를 업데이트 **/
	void		Update(sQuestUpdateData sData);

	/** Print quest information and status **/
	/** 퀘스트 정보 및 상태를 출력 **/
	void		PrintQuest();

private:

	/** Return true if all of the tasks in a quest is done	**/
	/** 모든 Task가 완료된 경우 true 리턴	**/
	bool		IsAllTaskDone();
};