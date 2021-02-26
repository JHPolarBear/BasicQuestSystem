#include <iostream>

#include "QuestSystem.h"

using namespace std;

CQuestSystem::CQuestSystem()
{
	m_questManager = new CQuestManager();
}

CQuestSystem::~CQuestSystem()
{
	if(m_questManager)
	{
		delete(m_questManager);
	}
}

void CQuestSystem::Initialize()
{
	if(!CheckManager())
		return;

	m_questManager->Initialize();
}

bool CQuestSystem::LoadLocalSavedData()
{
	if (!CheckManager())
		return false;

	return m_questManager->LoadLocalSavedData();
}

E_ASSIGN_QUEST CQuestSystem::AssignQuest(int _qid)
{
	if (!CheckManager())
		return E_ASSIGN_QUEST::FAIL_FIND_MANAGER;

	return m_questManager->AssignQuest(_qid);
}

bool CQuestSystem::SetPlayer(CPlayer* player)
{
	if (!CheckManager())
		return false;

	return m_questManager->SetPlayer(player);
}

void CQuestSystem::PrintQuestDataTable()
{
	if (!CheckManager())
		return;

	m_questManager->PrintQuestDataTable();
}

void CQuestSystem::PrintQuestList()
{
	if (!CheckManager())
		return;

	m_questManager->PrintQuestList();
}

void CQuestSystem::onNotify(E_EVENT_LISTENER_TYPE etype, CEventListener_Info_Base* sInfo)
{
	if (!CheckManager())
		return;

	sQuestUpdateData sData;

	CEventListener_Info_Quest* sEL_Quest_Data = (CEventListener_Info_Quest*)sInfo;

	sData.action = ConvertEventTypeToTaskAction(etype);
	sData.target = (E_TASK_TARGET)sEL_Quest_Data->GetTarget();
	sData.targetCount = sEL_Quest_Data->GetTargetCnt();
	sData.targetCountType = sEL_Quest_Data->GetTargetCntType();

	m_questManager->UpdateQuest(sData);
}

bool CQuestSystem::CheckManager()
{
	// print error message and return false if the manager is not exists
	if(!m_questManager)
	{
		FUNC_LOG("Quest manager not exists");
		return false;
	}

	return true;
}

E_TASK_ACTION CQuestSystem::ConvertEventTypeToTaskAction(E_EVENT_LISTENER_TYPE eType)
{
	E_TASK_ACTION action;

	switch (eType)
	{
	case E_EVENT_LISTENER_NONE:
		action = E_TASK_ACTION::NONE;
		break;
	case E_EVENT_LISTENER_PLAYER_HUNT:
		action = E_TASK_ACTION::HUNT;
		break;
	case E_EVENT_LISTENER_PLAYER_REACH:
		action = E_TASK_ACTION::REACH;
		break;
	case E_EVENT_LISTENER_PLAYER_COLLECT:
		action = E_TASK_ACTION::COLLECT;
		break;
	case E_EVENT_LISTENER_MAX:		
	default:
		action = E_TASK_ACTION::NONE;
		break;
	}

	return action;
}
