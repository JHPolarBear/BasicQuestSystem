#include "Quest.h"

#include <iostream>

using namespace std;

CQuest::CQuest()
{
	Id = 0;

	Title = "";

	Vec_Tasks.clear();

	Precede_Quest_Id = 0;
	Follow_Quest_Id = 0;

	State = QUEST_STATE_NONE;
}

CQuest::~CQuest()
{

}
