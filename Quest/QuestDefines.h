#pragma once

#define BASE_QUEST_DATASET	"Quest/Quest_Table.csv"
#define SAVE_QUEST_DATA		"Player/Saved_Quest_Data.csv"

#include "Task/TaskDefines.h"

// Maximul count of quest player can hold
// 플레이거가 가지고 있을 수 있는 최대 퀘스트 갯수
#define MAX_QUEST_COUNT	25

// Invalid Quest ID ( used to initialiaze CQuest information)
#define INVALID_QUEST_ID	0

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
	/**	CQuestData에 저장되는 Task 기본 정보.
		CQuest 클래스 생성 시 이 정보를 기반으로 CTask를 생성한다 **/
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
		target = E_TASK_TARGET::NONE;
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