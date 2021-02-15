#pragma once

#include <string>

#define _TASK_COUNT_MAX 999

/** Action type that task will accomplish **/
enum TASK_ACTION
{
	TASK_ACTION_NONE,

	TASK_ACTION_HUNT,		// hunt target monster
	TASK_ACTION_GOTO,		// move to target point
	TASK_ACTION_COLLECT,	// collect target item

	TASK_ACTION_MAX
};

/** State of task **/
enum TASK_STATE
{
	TASK_STATE_NONE,

	TASK_STATE_PROCESS,
	TASK_STATE_DONE,
	TASK_STATE_FAIL,

	TASK_STATE_MAX
};

/** Target of task **/
enum TASK_TARGET
{
	TASK_TARGET_NONE,

	// Target for hunt
	TASK_TARGET_WOLF,
	TASK_TARGET_GOBLIN,

	// Target for collect
	TASK_TARGET_BONE,

	// Target for reach point
	TASK_TARGET_START_TOWN,

	TASK_TARGET_MAX
};

/** Strcuture which contains information for task class **/
struct sTaskInfo
{
	// Task Description
	std::string desc;

	// Action Type
	TASK_ACTION actionType;

	// Target of Action
	TASK_TARGET target;
	
	// Count to accomplish task
	float		targetCount;

	sTaskInfo()
	{
		desc = "";
		actionType = TASK_ACTION_NONE;
		target = TASK_TARGET_NONE;
		targetCount = _TASK_COUNT_MAX;
	}

	sTaskInfo(int _actionType, int _target, float _count)
	{
		desc = "";
		actionType = (TASK_ACTION)_actionType;
		target = (TASK_TARGET)_target;
		targetCount = _count;
	}

	sTaskInfo& operator =(const sTaskInfo &other)
	{
		desc = other.desc;
		actionType = other.actionType;
		target = other.target;
		targetCount = other.targetCount;

		return *this;
	}
};