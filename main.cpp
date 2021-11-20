#include "main.h"

using namespace std;

// Sample Program to show how quest system works
int main()
{
	// Create player with usercode 1234
	player = new CPlayer(1234);

	//	Test Code - Print quest data table read form csv file
	//	QuestSystem.PrintQuestDataTable();

	//	Load local save file from csv
	bool bLoadSaveFile = GetPlayer()->LoadLocalSavedData();
	if(bLoadSaveFile == false)
	{
		// print error and exit program
		// 오류 출력 후 프로그램 종료
		EXT_LOG("Filaed to load save data");
		
		system("pause");
		return 0;
	}
	else
	{
		// print loaded player's quest lists
		// 로드한 플레이어의 퀘스트 리스트 출력
		cout << "Loaded quest lists" << endl << endl;
		GetPlayer()->PrintQuestList();
	}

	cout << "Press e to end program" << endl << endl;

	bool bLoop = true;
	while(bLoop)
	{
		char _cmd = 'i';		

		// print main menu
		ShowMainMenu();
		cin >> _cmd;

		cout << endl;
		// process main menu input 
		// exit loop if exit command called (bLoop changed to false)
		bLoop = ProcessMainMenuInput(_cmd);
	}

	/*
	// Sample code - assign new quest to player
	GetPlayer()->AssignQuest(103);

	//	Sample code - player notify event to all listener using notify function ( i.e) QuestSystem )
	//	Expect that player hunt a wolf

	system("pause");
	cout << endl;

	// Create event
	CEventListener_Info_Quest* sInfo = new CEventListener_Info_Quest();
	sInfo->SetTarget(E_TASK_TARGET::MON_WOLF);
	sInfo->SetTargetCnt(1.f);
	sInfo->SetTargetCntType(E_TASK_TARGET_CNT_TYPE::APPEND);

	// notify event to quest system
	GetPlayer()->Notify(E_EVENT_LISTENER_PLAYER_HUNT, sInfo);

	*/

	// delete player object on terminate
	delete(player);

	return 0;
}

// print main menu lists
void ShowMainMenu()
{
	cout << endl;
	cout << "Select Action : " << endl;
	cout << "1. Hunt Monster" << endl;
	cout << "2. Print Current Quests" << endl;
	cout << "e. exit game" << endl;
	cout << ": ";
}

// process main menu event input
bool ProcessMainMenuInput(char _cmd)
{
	bool bRes = true;

	switch(_cmd)
	{
		// exit command
		// 종료 시 false 리턴
		case 'e':
		{
			bRes = false;
			break;
		}

		case '1':
		{
			char _target = 'e';
			ShowHuntMenu();
			cin >> _target;
			ProcessHuntMenu(_target);
			break;
		}

		case '2':
		{
			GetPlayer()->PrintQuestList();
			break;
		}

		default:
		{
#ifdef _DEBUG
			EXT_LOG("Invalid command : %c", _cmd);
			break;
#endif
		}
	}

	return bRes;
}


void ShowHuntMenu()
{
	cout << endl;
	cout << "Select Target : " << endl;
	cout << "1. Wolve" << endl;
	cout << "2. Goblin" << endl;
	cout << ": ";
}

bool ProcessHuntMenu(char _target)
{
	bool bRes = true;

	E_TASK_TARGET eTarget = E_TASK_TARGET::MON_NONE;

	// Set target according to the 
	switch (_target)
	{		
		case '1':
		{
			eTarget = E_TASK_TARGET::MON_WOLF;
			break;
		} 
		case '2':
		{
			eTarget = E_TASK_TARGET::MON_GOBLIN;
			break;
		}

		case 'e':
		default:
		{
	#ifdef _DEBUG
			EXT_LOG("Invalid target : %c", _target);
			break;
	#endif
		}
	}

	// Create hunting event
	// 사냥 이벤트를 생성
	CEventListener_Info_Quest* sInfo = new CEventListener_Info_Quest();
	sInfo->SetTarget(eTarget);
	sInfo->SetTargetCnt(1.f);
	sInfo->SetTargetCntType(E_TASK_TARGET_CNT_TYPE::APPEND);

	// Notify hunting events to the event system registered in the player
	// 플레이어에 등록된 이벤트 시스템에 사냥 이벤트를 notify
	player->Notify(E_EVENT_LISTENER_PLAYER_HUNT, sInfo);

	return bRes;
}
