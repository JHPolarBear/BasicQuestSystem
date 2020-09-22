#pragma once

#include "TaskDefines.h"

class Task
{
public:
	Task();
	virtual ~Task();

	// Return whether task is done
	bool Done()		{return m_State == TASK_STATE_DONE;}
	void Update();

private:
	// Task Type
	TASK_TYPE m_Type;

	TASK_STATE m_State;

	

};
