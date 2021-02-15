#pragma once

#include "TaskDefines.h"

class CTask
{
private:
	// Task ID
	// id represent task's order written in quest_data.csv 
	int Id;

	// Information about task action
	sTaskInfo Info;

	// state of task
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
