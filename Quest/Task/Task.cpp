#include "Task.h"

#include "../../CommonDefines.h"

using namespace std;

CTask::CTask()
{
	Id = -1;

	actionType = E_TASK_ACTION::NONE;

	target = E_TASK_TARGET::NONE;

	targetCount = _TASK_COUNT_MAX;

	currentCount = 0;

	State = E_TASK_STATE::NONE;
}

CTask::CTask(int _id, int _actType, int _tgt, int _tgtCnt)
{
	Id = _id;

	actionType = (E_TASK_ACTION)_actType;

	target = (E_TASK_TARGET)_tgt;
	
	targetCount = _tgtCnt;

	currentCount = 0;

	State = E_TASK_STATE::NONE;
}

CTask::~CTask()
{
	
}

void CTask::Update(float _inputcnt, E_TASK_TARGET_CNT_TYPE _tgtcnt_type)
{
	switch (_tgtcnt_type)
	{	
	case E_TASK_TARGET_CNT_TYPE::APPEND:
		currentCount += _inputcnt;
		break;
	case E_TASK_TARGET_CNT_TYPE::UPDATE:
		currentCount = _inputcnt;
		break;
	case E_TASK_TARGET_CNT_TYPE::NONE:
	case E_TASK_TARGET_CNT_TYPE::MAX:
		FUNC_LOG("Invalid target count type: %d", (int)_tgtcnt_type);
	default:
		break;
	}

	// Change state to done if current count exceeds target count
	if(currentCount >= targetCount)
	{
		State = E_TASK_STATE::DONE;
	}
}

std::string CTask::GetStateString()
{
	string	strRes;

	switch(State)
	{
	case E_TASK_STATE::DONE:
		strRes = "Done";
		break;
	case E_TASK_STATE::ACTIVE:
		strRes = "In progress";
		break;
	case E_TASK_STATE::FAIL:
		strRes = "Fail";
		break;
	case E_TASK_STATE::NONE:
	case E_TASK_STATE::MAX:
	default:
		strRes = "Invalid State";
		break;
	}

	return strRes;
}
