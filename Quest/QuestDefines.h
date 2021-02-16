#pragma once

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

enum QUEST_STATE
{
	QUEST_STATE_NONE,

	QUEST_STATE_PROCESS,
	QUEST_STATE_SUCCESS,
	QUEST_STATE_FAIL,

	QUEST_STATE_MAX,
};