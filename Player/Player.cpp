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
}

CPlayer::~CPlayer()
{

}

bool CPlayer::LoadLocalSavedData()
{
	bool result = false;

	//Load Quest data
	result = QuestSystem->LoadLocalSavedData();

	return result;
}

void CPlayer::PrintQuestList()
{
	QuestSystem->PrintQuestList();
}

