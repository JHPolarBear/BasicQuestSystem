#pragma once

#include "TaskDefines.h"

/** CTask is a unit of work to accomplish quest 
	CQuest can hold multiple tasks for its function and 
	quest is accomplished when player finish all tasks **/
/** CTask는 퀘스트를 완료하기 위한 단위 작업을 의미합니다.
	퀘스트는 여러개의 CTask로 이루어질 수 있으며, 
	모든 Task를 완료해야 퀘스트를 성공할수 있습니다. **/
class CTask
{
private:
	/** Task ID
		id represent task's order written in quest_data.csv
		id는 CSV 파일에 적혀있는 task의 순서를 의미한다		**/
	int Id;

	/** Task Description **/
	std::string desc;

	/** Action Type **/
	E_TASK_ACTION actionType;

	/** Target of Action	**/
	E_TASK_TARGET target;

	/** Count to accomplish task **/
	float		targetCount;

	/**Player's current count **/
	float		currentCount;

	/** state of task **/
	E_TASK_STATE State;

public:
	CTask();
	CTask(int _id = -1, int _actType = 0, int _tgt = 0, int _tgtCnt = _TASK_COUNT_MAX);
	virtual ~CTask();


	// Return whether task is done
	bool IsDone()		{return State == E_TASK_STATE::DONE;}

	void Update(float _inputcnt, E_TASK_TARGET_CNT_TYPE _tgtcnt_type);


	/****	Getter && Setter	****/
	void		SetId(int _id)		{Id = _id;}
	int			GetId()				{return Id;}

	void			SetDesc(std::string _desc)	{desc = _desc;}
	std::string		GetDesc()					{return desc;}

	void			SetActionType(E_TASK_ACTION _actType)		{actionType = _actType;}
	E_TASK_ACTION		GetActionType()							{return actionType;}

	void			SetTarget(E_TASK_TARGET _tgt)				{target = _tgt;}
	E_TASK_TARGET		GetTarget()								{return target;}

	void			SetTargetCount(float _tgtCnt)			{targetCount = _tgtCnt;}
	float			GetTargetCount()						{return targetCount;}

	void			SetCurrentCount(float _cnt)				{currentCount = _cnt;}
	float			GetCurrentCount()						{return currentCount;}

	void			SetState(E_TASK_STATE _state)			{State = _state;}
	E_TASK_STATE		GetState()							{return State;}
	std::string		GetStateString();
};
