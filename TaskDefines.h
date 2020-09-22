#pragma once

// TYPICAL ID OF TASK
enum TASK_TYPE
{
	TASK_TYPE_NONE,

	TASK_TYPE_HUNT,		// hunt target monster
	TASK_TYPE_GOTO,		// move to target point
	TASK_TYPE_COLLECT,	// collect tartet item

	TASK_TYPE_MAX
};

// STATE OF TASK
enum TASK_STATE
{
	TASK_STATE_NONE,

	TASK_STATE_PROCESS,
	TASK_STATE_DONE,
	TASK_STATE_FAIL,

	TASK_STATE_MAX
};