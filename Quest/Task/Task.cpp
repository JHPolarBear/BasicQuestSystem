#include "Task.h"

CTask::CTask()
{
	Id = -1;

	Info.actionType = TASK_ACTION_NONE;
	Info.desc = "";
	Info.target = TASK_TARGET_NONE;
	Info.targetCount = _TASK_COUNT_MAX;

	State = TASK_STATE_NONE;
}

CTask::CTask(sTaskInfo _info, int _id)
{
	Id = _id;
	
	Info = _info;

	State = TASK_STATE_NONE;
}

CTask::~CTask()
{
	
}
