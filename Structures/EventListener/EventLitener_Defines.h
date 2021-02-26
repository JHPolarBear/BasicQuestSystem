#pragma once

// Include TaskDefines to define quest listener class
#include "../../Quest/Task/TaskDefines.h"

enum E_EVENT_LISTENER_TYPE
{
	E_EVENT_LISTENER_NONE,

	// player hunt monster
	E_EVENT_LISTENER_PLAYER_HUNT,

	E_EVENT_LISTENER_PLAYER_REACH,

	E_EVENT_LISTENER_PLAYER_COLLECT,

	E_EVENT_LISTENER_MAX,
};

// Base Information class for event listener input
class CEventListener_Info_Base
{
public:
	CEventListener_Info_Base()	{}
	virtual ~CEventListener_Info_Base()	{}
};

// listener information for quest event
class CEventListener_Info_Quest : public CEventListener_Info_Base
{
	// a Target for task
	E_TASK_TARGET Target;

	// Amount of the target
	float Target_Cnt;

	// way to treat target count
	E_TASK_TARGET_CNT_TYPE Target_Cnt_Type;

public:
	CEventListener_Info_Quest()
	{
		Target = E_TASK_TARGET::NONE;
		Target_Cnt = 0.f;

		Target_Cnt_Type = E_TASK_TARGET_CNT_TYPE::NONE;
	}

	CEventListener_Info_Quest(E_TASK_TARGET _tgt, float _tgtcnt, E_TASK_TARGET_CNT_TYPE _tgtcnt_type)
	{
		Target = _tgt;
		Target_Cnt = _tgtcnt;

		Target_Cnt_Type = _tgtcnt_type;
	}

	~CEventListener_Info_Quest()	{}

	/**** Getter && Setter ****/

	void	SetTarget(E_TASK_TARGET _val)			{ Target = _val; }
	E_TASK_TARGET		GetTarget()					{ return Target;}
	
	void	SetTargetCnt(float _val)				{ Target_Cnt = _val; }
	float	GetTargetCnt()							{ return Target_Cnt; }

	void	SetTargetCntType(E_TASK_TARGET_CNT_TYPE _val)	{ Target_Cnt_Type = _val; }
	E_TASK_TARGET_CNT_TYPE GetTargetCntType()				{ return Target_Cnt_Type; }
};