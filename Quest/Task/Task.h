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
		id represent task's order written in quest_data.csv **/
	/** id�� CSV ���Ͽ� �����ִ� task�� ������ �ǹ��Ѵ� **/
	int Id;

	/** Information about task action	**/
	/** Task�� �����ؾ� �ϴ� ����		**/
	sTaskInfo Info;

	/** state of task **/
	/** CTask�� ���� **/
	TASK_STATE State;

public:
	CTask();
	CTask(sTaskInfo _info, int _id = -1);
	virtual ~CTask();


	// Return whether task is done
	bool IsDone()		{return State == TASK_STATE_DONE;}

	void Update();


	/****	Getter && Setter	****/
	void		SetId(int _id)		{Id = _id;}
	int			GetId()				{return Id;}

	void		SetState(TASK_STATE _state)	{State = _state;}
	TASK_STATE	GetState()					{return State;}

	void		SetInfo(sTaskInfo _Info)	{Info = _Info;}
	sTaskInfo	GetInfo()					{return Info;}
};
