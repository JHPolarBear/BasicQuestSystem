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

	m_questManager->LoadLocalSavedData();
}

bool CQuestSystem::SetPlayer(CPlayer* player)
{
	if (!CheckManager())
		return false;

	m_questManager->SetPlayer(player);
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

bool CQuestSystem::CheckManager()
{
	// print error message and return false if the manager is not exists
	if(!m_questManager)
	{
		cout << "[" __FUNCTION__ << "] Quest manager not exists" << endl;
		return false;
	}

	return true;
}
