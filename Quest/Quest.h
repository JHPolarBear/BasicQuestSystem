#pragma once

#include <vector>

#include "QuestDefines.h"
#include "QuestDataTable.h"

/** Quest class used to handle actual player quest lists
	Inherit CQuestData and add State value to control quest process **/
/** 실제 플레이어가 수행중인 퀘스트를 관리하기 위한 클래스
	CQuestData를 상속 받아 State 값을 추가하여 사용					**/
class CQuest:public CQuestData
{
public:
	CQuest();
	virtual ~CQuest();

private:
	
	QUEST_STATE State;

public:
	/****	Getter && Setter	****/
	void			SetState(QUEST_STATE _state)	{State = _state;}
	QUEST_STATE		GetState()				{return State;}
};