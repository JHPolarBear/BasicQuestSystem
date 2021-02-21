#pragma once

enum E_EVENT_LISTENER_TYPE
{
	E_EVENT_LISTENER_NONE,

	// player hunt monster
	E_EVENT_LISTENER_PLAYER_HUNT,

	E_EVENT_LISTENER_PLAYER_REACH,

	E_EVENT_LISTENER_PLAYER_COLLECT,

	E_EVENT_LISTENER_MAX,
};

struct sEventListener_Info
{
	// Object related to event
	int Object_Id;

	// object count
	int Object_Cnt;

	sEventListener_Info()
	{
		Object_Id = 0;
		Object_Cnt = 0;
	}
};