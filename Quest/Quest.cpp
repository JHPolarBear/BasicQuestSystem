#include "Quest.h"

#include "../CommonDefines.h"

#include <iostream>

using namespace std;

CQuest::CQuest()
{
	Id = 0;

	Title = "";

	Vec_Tasks.clear();

	Vec_Rewards.clear();

	Precede_Quest_Id = 0;
	Follow_Quest_Id = 0;

	State = QUEST_STATE_NONE;
}

CQuest::~CQuest()
{

}

bool CQuest::RestoreSavedDatas(sSavedQuestData saveData)
{
	if (saveData.vec_Task_Ids.size() != Vec_Tasks.size())
	{
		FILE_LOG("Save data's task size not matched with Vec_Task");
		return false;
	}

	for(int i=0; i<saveData.vec_Task_Ids.size(); i++)
	{
		if(saveData.vec_Task_Ids[i] == Vec_Tasks[i].GetId())
		{
			Vec_Tasks[i].SetCurrentCount(saveData.vec_Task_Vals[i]);

			// Set task state compare current count with target count
			if(Vec_Tasks[i].GetTargetCount() == Vec_Tasks[i].GetCurrentCount())
			{
				Vec_Tasks[i].SetState(TASK_STATE_DONE);
			}
			else
			{
				Vec_Tasks[i].SetState(TASK_STATE_PROCESS);
			}
		}
	}

	// Set quest state in progress
	State = QUEST_STATE_PROCESS;

	return true;
}

void CQuest::PrintQuest()
{
	cout << "*************************************************************************" << endl;
	cout << "[Quest ID: " << GetId() << " / Quest Title: " << GetTitle() << " ]" << endl;
	cout << "[Precede Quest ID: " << GetPrecedeQuestId() << " / Follow Quest ID: " << GetFollowQuestId() << " ]" << endl << endl;

	for(int i=0; i<Vec_Tasks.size(); i++)
	{
		cout << "[Task " << i << ": Task_ID: " << Vec_Tasks[i].GetId() << " / Task_Action: " << Vec_Tasks[i].GetActionType() <<	"/ Task_Target: " << Vec_Tasks[i].GetTarget() 
			<< "\n/ Task_Target_Count: " << Vec_Tasks[i].GetTargetCount() << " / Task_Crnt_Count: " << Vec_Tasks[i].GetCurrentCount() << " / Task_State: " << Vec_Tasks[i].GetStateString() << " ]" << endl << endl;
	}
	
	std::vector<sReward> _vecReward = GetRewards();
	for (int i = 0; i < _vecReward.size(); i++)
	{
		sReward _reward = _vecReward[i];
		cout << "[Reward " << i << ": Reward_ID: " << _reward.Id << " / Reward_Count: " << _reward.Count << " ]" << endl;
	}
	cout << "*************************************************************************" << endl;

	cout <<endl;
}
