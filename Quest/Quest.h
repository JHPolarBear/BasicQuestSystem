#pragma once

#include <vector>

#include "Task/Task.h"
#include "QuestDefines.h"

class CQuest{

public:
	CQuest();
	virtual ~CQuest();

	// Print Basic information about the quest itself
	void PrintInfo();

private:
	/** Quest ID - Every Quest has unique ID **/
	int Id;

	/** Title of the quest **/
	std::string Title;

	/** List of tasks to be accomplished to complete quest **/
	std::vector<CTask> Vec_Tasks;

	/** List of Rewards given when quest is done **/
	std::vector<sReward> Vec_Rewards;

	/** Quest that must precede the current quest **/
	int Precede_Quest_Id;

	/** Quests that must follow the current quest **/
	int Follow_Quest_Id;


public:
	/****	Getter && Setter	****/
	void			SetId(int _id)					{Id = _id;}
	int				GetId()							{return Id;}

	void			SetTitle(std::string _title)	{Title = _title;}
	std::string		GetTitle()						{return Title;}

	void			SetPrecedeQuestId(int _precedId)	{Precede_Quest_Id = _precedId;}
	int				GetPrecedeQuestId()					{return Precede_Quest_Id;}

	void			SetFollowQuestId(int _followId)		{Follow_Quest_Id = _followId;}
	int				GetFollowQuestId()					{return Follow_Quest_Id;}

	void				SetVecTasks(std::vector<CTask> _vec_tasks)	{Vec_Tasks = _vec_tasks;}
	std::vector<CTask>	GetVecTasks()								{return Vec_Tasks;}

	void					SetRewards(std::vector<sReward> _vec_rewards)	{Vec_Rewards = _vec_rewards;}
	std::vector<sReward>	GetRewards()									{return Vec_Rewards;}

};