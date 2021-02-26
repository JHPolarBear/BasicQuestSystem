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
	int Id;

	/** Title of the quest **/
	std::string Title;

	/**	List of tasks that should be done to accomplish the quest**/
	std::vector<CTask> Vec_Tasks;

	/** List of Rewards given when quest is done **/
	std::vector<sReward> Vec_Rewards;

	/** Quest that must precede the current quest
		0 if precede quest not exists		**/
	int Precede_Quest_Id;

	/** Quests that must follow the current quest
		0 if following quest not exists		**/
	int Follow_Quest_Id;
	
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
	bool		RestoreSavedDatas(sQuestLoadData savdData);
	 
	/** Update Quest - udate all tasks and quest state according to the state of all tasks **/
	void		Update(sQuestUpdateData sData);

	/** Print quest information and status **/
	void		PrintQuest();

private:

	/** Return true if all of the tasks in a quest is done	**/
	bool		IsAllTaskDone();
};