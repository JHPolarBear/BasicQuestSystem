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

void CQuestSystem::onNotify(E_EVENT_LISTENER_TYPE etype, sEventListener_Info sInfo)
{
	if (!CheckManager())
		return;

	m_questManager->UpdateQuest(etype,  sInfo);
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
