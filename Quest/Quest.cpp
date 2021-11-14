#include "Quest.h"

#include "../CommonDefines.h"

#include <iostream>

using namespace std;

CQuest::CQuest()
{
	Id = INVALID_QUEST_ID;

	Title = "";

	Vec_Tasks.clear();

	Vec_Rewards.clear();

	Precede_Quest_Id = 0;
	Follow_Quest_Id = 0;

	State = E_QUEST_STATE::NONE;
}

CQuest::~CQuest()
{

}

bool CQuest::RestoreSavedDatas(sQuestLoadData saveData)
{
	// 세이브 데이터의 Task 항목과 실제 퀘스트의 Task 갯수가 일치하지 않는 경우 복구 실패
	if (saveData.vec_Task_Ids.size() != Vec_Tasks.size())
	{
		EXT_LOG("Save data's task size not matched with Vec_Task");
		return false;
	}

	// 세이브 데이터에 기록된 테스트 ID와 일치하는 Task 항목이 있는 경우
	// 해당 Task 달성 기록을 복구한다
	for(int i=0; i<saveData.vec_Task_Ids.size(); i++)
	{
		if(saveData.vec_Task_Ids[i] == Vec_Tasks[i].GetId())
		{
			Vec_Tasks[i].SetCurrentCount(saveData.vec_Task_Vals[i]);

			// Set task state compare current count with target count
			if(Vec_Tasks[i].GetTargetCount() == Vec_Tasks[i].GetCurrentCount())
			{
				Vec_Tasks[i].SetState(E_TASK_STATE::DONE);
			}
			else
			{
				Vec_Tasks[i].SetState(E_TASK_STATE::ACTIVE);
			}
		}
	}

	// Set quest state active
	// 퀘스트 상태 활성화
	State = E_QUEST_STATE::ACTIVE;

	return true;
}

void CQuest::Update(sQuestUpdateData sData)
{
	bool bFin = false;

	for(int i=0; i<Vec_Tasks.size(); i++)
	{
		if(Vec_Tasks[i].GetActionType() == sData.action \
			&& Vec_Tasks[i].GetTarget() == sData.target)
		{
			Vec_Tasks[i].Update(sData.targetCount, sData.targetCountType);
		}
	}

	// Change quest state according to task state
	// Consider fail condition later
	if(IsAllTaskDone())
	{
		State = E_QUEST_STATE::SUCCESS;
	}

	// Add Action according to quest state
	switch (State)
	{
	case E_QUEST_STATE::ACTIVE:
		// nothing to do
		break;
	case E_QUEST_STATE::SUCCESS:
		//// A. if consider only local environment
		// 1. notice player succeed quest
		// 2. Add result to player slot
		// 3. delete quest from the list


		//// B. if with network condition 
		// send result to server 
		// then change state to send result
		break;
	// only for network condition
	case E_QUEST_STATE::SEND_RESULT:
		// nothing to do in update state
		// delete quest from the list after receive result from server
		break;
	case E_QUEST_STATE::FAIL:
		// consider later
		break;
	// invalid state for possessed quest
	case E_QUEST_STATE::NONE:
	case E_QUEST_STATE::MAX:
		FUNC_LOG("Invalid quest state: %d", (int)State);
	default:
		break;
	}
}

void CQuest::PrintQuest()
{
	cout << "*************************************************************************" << endl;
	cout << "[Quest ID: " << GetId() << " / Quest Title: " << GetTitle() << " ]" << endl;
	cout << "[Precede Quest ID: " << GetPrecedeQuestId() << " / Follow Quest ID: " << GetFollowQuestId() << " ]" << endl << endl;

	for(int i=0; i<Vec_Tasks.size(); i++)
	{
		cout << "[Task " << i << ": Task_ID: " << Vec_Tasks[i].GetId() << " / Task_Action: " << (int)Vec_Tasks[i].GetActionType() <<	"/ Task_Target: " << (int)Vec_Tasks[i].GetTarget() 
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

bool CQuest::IsAllTaskDone()
{
	bool bRes = true;

	for (int i = 0; i < Vec_Tasks.size(); i++)
	{
		if(Vec_Tasks[i].IsDone() == false)
		{
			bRes = false;
			break;
		}
	}

	return bRes;
}
