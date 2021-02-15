#include "Task.h"

Task::Task()
{
	id = -1;

	info.actionType = TASK_ACTION_NONE;
	info.desc = "";
	info.target = TASK_TARGET_NONE;
	info.targetCount = _TASK_COUNT_MAX;

	state = TASK_STATE_NONE;
}

Task::Task(sTaskInfo _info, int _id)
{
	id = id;
	
	info = _info;
}

Task::~Task()
{
	
}
