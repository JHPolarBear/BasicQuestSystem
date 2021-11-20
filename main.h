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
// ����Ʈ ����� �׽�Ʈ�ϱ� ���� ������Ʈ��, ���� �÷��̾� �Ŵ��� ���� �÷��̾� ��ü�� �������� ����
CPlayer* player;

CPlayer* GetPlayer()	{return player;}