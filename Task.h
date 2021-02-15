#pragma once

#include "TaskDefines.h"

class Task
{
public:
	Task();
	Task(sTaskInfo _info, int id = -1);
	virtual ~Task();


	// Return whether task is done
	bool IsDone()		{return state == TASK_STATE_DONE;}

	void Update();

private:
	// Task ID
	// id represent task's order written in quest_data.csv 
	int id;

	// Information about task action
	sTaskInfo info;
	
	// state of task
	TASK_STATE state;
};
