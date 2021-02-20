#pragma once

#define _MAX_TASKINFO_JSON_SIZE 512

/*	Packet Struct 
	prefix:	sPkt							
	SToC: From Server to client	*/
/*	CToS: From Client to Server	*/

struct sPktCTOSRequestQuestList
{
	int usercode;

	sPktCTOSRequestQuestList()
	{
		usercode = 0;
	}
};

// Server: Send requested player's quest list to client
struct sPktStoCRequestQuestList
{
	// usercode of requested player
	int usercode;

	// number of quest current player has.
	int questCnt;

	sPktStoCRequestQuestList()
	{
		usercode = 0;
		questCnt = 0;
	}
};
//List of sNetQuestInfo are attached to this packet

// quest information with id and json(save data)
struct sNetQuestInfo
{
	// quest id
	int questId;

	// Json Data for Quest's tasks
	// i.e) {"TaskId":[1,2,3],"TaskCurrent":[1,0,2]}
	char TaskInfoJson[_MAX_TASKINFO_JSON_SIZE];

	sNetQuestInfo()
	{
		questId = 0;
	}
};

// Client : send player's quest data to update quest's state
struct sPktCToSUpdateQuest
{
	// player id
	int usercode;

	sNetQuestInfo sQuestSave;

	sPktCToSUpdateQuest()
	{
		usercode = 0;
	}
};