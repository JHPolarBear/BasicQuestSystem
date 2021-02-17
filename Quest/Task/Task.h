#pragma once

#include "TaskDefines.h"

/** CTask is a unit of work to accomplish quest 
	CQuest can hold multiple tasks for its function and 
	quest is accomplished when player finish all tasks **/
/** CTask�� ����Ʈ�� �Ϸ��ϱ� ���� ���� �۾��� �ǹ��մϴ�.
	����Ʈ�� �������� CTask�� �̷���� �� ������, 
	��� Task�� �Ϸ��ؾ� ����Ʈ�� �����Ҽ� �ֽ��ϴ�. **/
class CTask
{
private:
	/** Task ID
		id represent task's order written in quest_data.csv
		id�� CSV ���Ͽ� �����ִ� task�� ������ �ǹ��Ѵ�		**/
	int Id;

	/** Task Description **/
	std::string desc;

	/** Action Type **/
	TASK_ACTION actionType;

	/** Target of Action	**/
	TASK_TARGET target;

	/** Count to accomplish task **/
	float		targetCount;

	/**Player's current count **/
	float		currentCount;

	/** state of task **/
	TASK_STATE State;

public:
	CTask();
	CTask(int _id = -1, int _actType = 0, int _tgt = 0, int _tgtCnt = _TASK_COUNT_MAX);
	virtual ~CTask();


	// Return whether task is done
	bool IsDone()		{return State == TASK_STATE_DONE;}

	void Update();


	/****	Getter && Setter	****/
	void		SetId(int _id)		{Id = _id;}
	int			GetId()				{return Id;}

	void		SetState(TASK_STATE _state)	{State = _state;}
	const TASK_STATE	GetState()					{return State;}
};
