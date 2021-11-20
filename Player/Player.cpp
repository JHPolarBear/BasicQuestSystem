#include "Player.h"

CQuestSystem* CPlayer::QuestSystem;

CPlayer::CPlayer()
{
	if(QuestSystem != nullptr)
	{
		delete(QuestSystem);
	}

	QuestSystem = new CQuestSystem();

	// Save self pointer to Quest system
	QuestSystem->SetPlayer(this);

	// Add QuestSyem to event listener itself
	Register(QuestSystem);
}

CPlayer::CPlayer(int _usercode)
{	
	if (QuestSystem != nullptr)
	{
		delete(QuestSystem);
	}

	QuestSystem = new CQuestSystem();

	UserCode = _usercode;

	QuestSystem->SetPlayer(this);

	// Add QuestSyem to event listener itself
	Register(QuestSystem);
}

CPlayer::~CPlayer()
{
	if(QuestSystem != nullptr)
		delete QuestSystem;
}

bool CPlayer::LoadLocalSavedData()
{
	bool result = false;

	//Load Quest data
	result = QuestSystem->LoadLocalSavedData();

	return result;
}

E_ASSIGN_QUEST CPlayer::AssignQuest(int _qid)
{
	return QuestSystem->AssignQuest(_qid);
}

void CPlayer::PrintQuestList()
{
	QuestSystem->PrintQuestList();
}

