#pragma once

#include <iostream>
#include <string>

#include "Quest/QuestSystem.h"
#include "Player/Player.h"

#include "CommonDefines.h"

// Main function
int main();

// print main menu lists
void ShowMainMenu();

// process main menu event input
// @param  _cmd : selected main menu type
// @return : return false if exit command inserted
bool ProcessMainMenuInput(char _cmd);

// print hunt target lists
void ShowHuntMenu();

// process hunt target type
// @param  _target : monster type ( ex) wolf, goblin, etc... )
bool ProcessHuntMenu(char _target);

// Sample Player
// 퀘스트 기능을 테스트하기 위한 프로젝트로, 별도 플레이어 매니저 없이 플레이어 객체를 전역으로 선언
CPlayer* player;

CPlayer* GetPlayer()	{return player;}