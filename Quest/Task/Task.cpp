#include "Task.h"

using namespace std;

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

std::string CTask::GetStateString()
{
	string	strRes;

	switch(State)
	{
	case TASK_STATE_DONE:
		strRes = "Done";
		break;
	case TASK_STATE_PROCESS:
		strRes = "In progress";
		break;
	case TASK_STATE_FAIL:
		strRes = "Fail";
		break;
	case TASK_STATE_NONE:
	case TASK_STATE_MAX:
	default:
		strRes = "Invalid State";
		break;
	}

	return strRes;
}
