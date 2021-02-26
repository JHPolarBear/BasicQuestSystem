#pragma once

#include <string>

#define _TASK_COUNT_MAX 999

/** Action type that task will accomplish **/
enum class E_TASK_ACTION
{
	NONE,

	HUNT,		// hunt target monster
	REACH,		// move to target point
	COLLECT,	// collect target item

	MAX
};

// How to treat update target count with saved count
enum class E_TASK_TARGET_CNT_TYPE
{
	NONE,

	APPEND,			// Append
	UPDATE,			// Delete original value and update to new value

	MAX
};

/** State of task **/
enum class E_TASK_STATE
{
	NONE,

	ACTIVE,
	DONE,
	FAIL,

	MAX
};

/** Target of task **/
enum class E_TASK_TARGET
{
	NONE,

	// Target for hunt
	MON_WOLF,
	MON_GOBLIN,

	// Target for collect
	ITEM_BONE,

	// Target for reach point
	LOC_TOWN_1,

	MAX
};