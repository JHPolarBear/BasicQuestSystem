#pragma once

#include <vector>

#include "QuestDefines.h"
#include "QuestDataTable.h"

/** Quest class used to handle actual player quest lists
	Inherit CQuestData and add State value to control quest process **/
/** ���� �÷��̾ �������� ����Ʈ�� �����ϱ� ���� Ŭ����
	CQuestData�� ��� �޾� State ���� �߰��Ͽ� ���					**/
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