#pragma once

#include "TaskDefines.h"

/** CTask is a unit of work to accomplish quest 
	CQuest can hold multiple tasks for its function and 
	quest is accomplished when player finish all tasks **/
/** CTask는 퀘스트를 완료하기 위한 단위 작업을 의미합니다.
	퀘스트는 여러개의 CTask로 이루어질 수 있으며, 
	모든 Task를 완료해야 퀘스트를 성공할수 있습니다. **/
class CTask
{
private:
	/** Task ID
		id represent task's order written in quest_data.csv **/
	/** id는 CSV 파일에 적혀있는 task의 순서를 의미한다 **/
	int Id;

	/** Information about task action	**/
	/** Task가 수행해야 하는 정보		**/
	sTaskInfo Info;

	/** state of task **/
	/** CTask의 상태 **/
	TASK_STATE State;

public:
	CTask();
	CTask(sTaskInfo _info, int _id = -1);
	virtual ~CTask();


	// Return whether task is done
	bool IsDone()		{return State == TASK_STATE_DONE;}

	void Update();


	/****	Getter && Setter	****/
	void		SetId(int _id)		{Id = _id;}
	int			GetId()				{return Id;}

	void		SetState(TASK_STATE _state)	{State = _state;}
	TASK_STATE	GetState()					{return State;}

	void		SetInfo(sTaskInfo _Info)	{Info = _Info;}
	sTaskInfo	GetInfo()					{return Info;}
};
