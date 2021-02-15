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