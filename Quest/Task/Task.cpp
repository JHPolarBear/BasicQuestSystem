#include "Task.h"

CTask::CTask()
{
	Id = -1;

	actionType = TASK_ACTION_NONE;

	target = TASK_TARGET_NONE;

	targetCount = _TASK_COUNT_MAX;

	currentCount = 0;

	State = TASK_STATE_NONE;
}

CTask::CTask(int _id, int _actType, int _tgt, int _tgtCnt)
{
	Id = _id;

	actionType = (TASK_ACTION)_actType;

	target = (TASK_TARGET)_tgt;
	
	targetCount = _tgtCnt;

	currentCount = 0;

	State = TASK_STATE_NONE;
}

CTask::~CTask()
{
	
}
