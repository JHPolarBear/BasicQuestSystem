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