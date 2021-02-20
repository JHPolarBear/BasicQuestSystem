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

void CQuestSystem::RequestQuestList(int _usercode)
{
	if (!CheckManager())
		return;

	m_questManager->RequestQuestList(_usercode);
}

void CQuestSystem::ReceiveQuestList(/*char* pMsg*/)
{
	if (!CheckManager())
		return;

	m_questManager->ReceiveQuestList();
}


void CQuestSystem::SendUpdateQuest(int _usercode, int _qId)
{
	if (!CheckManager())
		return;

	m_questManager->SendUpdateQuest(_usercode, _qId);
}

void CQuestSystem::PrintQuestDataTable()
{
	if (!CheckManager())
		return;

	m_questManager->PrintQuestDataTable();
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
