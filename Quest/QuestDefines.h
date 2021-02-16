#pragma once

#define BASE_QUEST_DATASET "Quest/Quest_Table.csv"

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

enum QUEST_STATE
{
	QUEST_STATE_NONE,

	QUEST_STATE_PROCESS,
	QUEST_STATE_SUCCESS,
	QUEST_STATE_FAIL,

	QUEST_STATE_MAX,
};