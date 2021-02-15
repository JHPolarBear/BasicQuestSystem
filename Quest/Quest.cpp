#include "Quest.h"

#include <iostream>

using namespace std;


CQuest::CQuest()
{

}

CQuest::~CQuest()
{

}

void CQuest::PrintInfo()
{
	cout << "[Quest ID: " << GetId() << " / Quest Title: " << GetTitle() << " ]" << endl;
	cout << "[Precede Quest ID: " << GetPrecedeQuestId() << " / Follow Quest ID: " << GetFollowQuestId() << " ]" << endl;

	std::vector<CTask> _vecTask = GetVecTasks();
	for (int i = 0; i < _vecTask.size(); i++)
	{
		CTask _task = _vecTask[i];
		sTaskInfo _info = _task.GetInfo();
		cout << "[Task " << i << ": Task_ID: " << _task.GetId() << " / Task_Action: " << _info.actionType <<
			" / Task_Target: " << _info.target << " / Task_Count: " << _info.targetCount << " / Task_State: " << _task.GetState() << " ]" << endl;
	}

	std::vector<sReward> _vecReward = GetRewards();
	for (int i = 0; i < _vecReward.size(); i++)
	{
		sReward _reward = _vecReward[i];
		cout << "[Reward " << i << ": Reward_ID: " << _reward.Id << " / Reward_Count: " << _reward.Count << " ]" << endl;
	}

	cout << endl << endl;
}
