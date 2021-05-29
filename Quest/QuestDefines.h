#pragma once

#define BASE_QUEST_DATASET	"Quest/Quest_Table.csv"
#define SAVED_QUEST_DATA		"Player/Saved_Quest_Data.csv"

#include "Task/TaskDefines.h"

// Maximul count of quest player can hold
// �÷��̰Ű� ������ ���� �� �ִ� �ִ� ����Ʈ ����
#define MAX_QUEST_COUNT	25

// Invalid Quest ID ( used to initialiaze CQuest information)
#define INVALID_QUEST_ID	0

// Quest data csv headers
#define DATASET_HEADER_ID			"ID"
#define DATASET_HEADER_TITLE		"TITLE"
#define DATASET_HEADER_TASK_ACTS	"TASK_ACTS"
#define DATASET_HEADER_TASK_TGTS	"TASK_TGTS"
#define DATASET_HEADER_TASK_CNTS	"TASK_CNTS"
#define DATASET_HEADER_REWARD_IDS	"REWARD_IDS"
#define DATASET_HEADER_REWARD_CNTS	"REWARD_CNTS"
#define DATASET_HEADER_PRECEDE_QID	"PRECEDE_QID"
#define DATASET_HEADER_FOOLW_QID	"FOLLOW_QID"

// structure for quest reward
struct sReward
{
	int Id;
	int Count;

	sReward()
	{
		Id = 0;
		Count = 0;
	}

	sReward(int _id, int _cnt)
	{
		Id = _id;
		Count = _cnt;
	}
};

/** struct for task base data saved in CQuestData
	CQuest class create CTask class based on this data **/
	/**	CQuestData�� ����Ǵ� Task �⺻ ����.
		CQuest Ŭ���� ���� �� �� ������ ������� CTask�� �����Ѵ� **/
struct sTaskData
{
	int action;
	int target;
	float targetCount;

	sTaskData(int _act, int _tgt, float _tgtcnt)
	{
		action = _act;
		target = _tgt;
		targetCount = _tgtcnt;
	}
};


// CSV data format for saved quest data
struct sQuestLoadData {
	int questId;
	std::vector<int> vec_Task_Ids;
	std::vector<float> vec_Task_Vals;

	sQuestLoadData()
	{
		questId = 0;
		vec_Task_Ids.clear();
		vec_Task_Vals.clear();
	}

};

// Structure for quest update input data
struct sQuestUpdateData
{
	E_TASK_ACTION	action;						// Task action

	E_TASK_TARGET	target;						// Task target

	float			targetCount;				// amount of target

	E_TASK_TARGET_CNT_TYPE targetCountType;		// way to treat target count (append, update ...)

	sQuestUpdateData()
	{
		action = E_TASK_ACTION::NONE;
		target = E_TASK_TARGET::MON_NONE;
		targetCount = 0.f;
		targetCountType = E_TASK_TARGET_CNT_TYPE::NONE;
	}

	sQuestUpdateData(E_TASK_ACTION _act, E_TASK_TARGET _tgt, float _tgtcnt, E_TASK_TARGET_CNT_TYPE _tgtcnt_type)
	{
		action = _act;
		target = _tgt;
		targetCount = _tgtcnt;
		targetCountType = _tgtcnt_type;
	}
};

enum class E_QUEST_STATE
{
	NONE,

	ACTIVE,			// Quest in progress
	SUCCESS,		// Success Quest
	SEND_RESULT,	// On sending result to server
	FAIL,			// Failed quest

	MAX,
};

enum class E_ASSIGN_QUEST
{
	NONE,

	SUCCESS,				// success create quest
	ALREAD_EXIST,				// same quest already exists
	FAIL_ON_CREATION,			// failed on CQuest creation
	FAIL_FIND_MANAGER,		// failed to access quest manager

	MAX,
};