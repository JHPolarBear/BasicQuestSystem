#pragma once

#include <map>

#include "QuestDefines.h"
#include "Task/Task.h"

/** Class To save Quest Raw Information **/
/** ����Ʈ ������ �����ϱ� ���� Ŭ���� **/
class CQuestData {

public:
	CQuestData();
	virtual ~CQuestData();

	// Print Basic information about the quest itself
	void PrintQuestData();

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
	void			SetId(int _id) { Id = _id; }
	int				GetId() { return Id; }

	void			SetTitle(std::string _title) { Title = _title; }
	std::string		GetTitle() { return Title; }

	void			SetPrecedeQuestId(int _precedId) { Precede_Quest_Id = _precedId; }
	int				GetPrecedeQuestId() { return Precede_Quest_Id; }

	void			SetFollowQuestId(int _followId) { Follow_Quest_Id = _followId; }
	int				GetFollowQuestId() { return Follow_Quest_Id; }

	void				SetVecTasks(std::vector<CTask> _vec_tasks) { Vec_Tasks = _vec_tasks; }
	std::vector<CTask>	GetVecTasks() { return Vec_Tasks; }

	void					SetRewards(std::vector<sReward> _vec_rewards) { Vec_Rewards = _vec_rewards; }
	std::vector<sReward>	GetRewards() { return Vec_Rewards; }
};

/** Map to manage all Quest Data in the game **/
/** ���� ���� �����ϴ� ��� Quest Data�� �����ϱ� ���� Map **/
typedef std::map<int, CQuestData> QUEST_DATA_TABLE;

/** Class to manage all Quest Data in the game **/
/** ���� ���� �����ϴ� ��� Quest Data�� �����ϱ� ���� Ŭ���� **/
class CQuestDataTable
{
public:
	CQuestDataTable();
	virtual ~CQuestDataTable();

private:
	/** Quest Data Table
		[Param] QId: Unique Quest Id  / QData: Quest Information
		Save Quest Data table with std::map to accelerate search speed	 **/	
	/**	�˻� �ӵ��� ���̱� ���� std::map�� ����Ͽ� ����	 **/
	QUEST_DATA_TABLE Quest_Data_Map;

public:

	// Read Qeust Data Table From csv
	// CSV ���Ͽ��� ����Ʈ ������ ���̺��� �о����
	bool	ReadDataTable();

	// return CQuestData matched to qid
	CQuestData GetQuestData(int _qid);

	/**** Dev Option ****/
	/**** ���߿� �ʿ��� ��� ****/

	// Print Quest Data table read from csv file
	// CSV ���Ͽ��� �о���� ����Ʈ ������ ���̺� ���
	void PrintQuestDataTable();
};