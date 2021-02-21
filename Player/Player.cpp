#include "Player.h"


CPlayer::CPlayer()
{
	// Save self pointer to Quest system
	QuestSystem.SetPlayer(this);
}

CPlayer::CPlayer(int _usercode)
{	
	UserCode = _usercode;

	QuestSystem.SetPlayer(this);
}

CPlayer::~CPlayer()
{

}

bool CPlayer::LoadLocalSavedData()
{
	bool result = false;

	//Load Quest data
	result = QuestSystem.LoadLocalSavedData();

	return result;
}

void CPlayer::PrintQuestList()
{
	QuestSystem.PrintQuestList();
}

