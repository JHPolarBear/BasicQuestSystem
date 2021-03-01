#pragma once

#include <string>

#define _TASK_COUNT_MAX 999

/** Action type that task will accomplish **/
enum class E_TASK_ACTION
{
	NONE,

	HUNT,		// hunt target monster	
	COLLECT,	// collect target item
	REACH,		// move to target point

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
	// Target for hunt
	MON_NONE = 0,
	MON_WOLF = 1,
	MON_GOBLIN,

	// Target for collect
	ITEM_NONE = 1000,
	ITEM_BONE = 1001,
	ITEM_APPLE = 1002,
	ITEM_FLOUR = 1003,
	ITEM_BUTTER = 1004,

	// Target for reach point
	LOC_NONE = 5000,
	LOC_TOWN_1 = 5001,

	MAX
};