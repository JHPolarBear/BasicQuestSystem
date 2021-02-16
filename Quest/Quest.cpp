#include "Quest.h"

#include <iostream>

using namespace std;

CQuest::CQuest()
{
	CQuestData();

	State = QUEST_STATE_NONE;
}

CQuest::~CQuest()
{

}
