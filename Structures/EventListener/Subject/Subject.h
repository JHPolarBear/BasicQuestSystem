#pragma once

/********************************************************************************
* Subject Calss - Manage observe objects with list(vector>
* Use Notify() function to pass event to registered observers when event occurs
* 대상 클래스 - 자신을 관찰하는 관찰자 인스턴스 리스트로 관리하며, 
* 이벤트 발생 시 등록된 관찰자들에게 Notify로 이벤트를 전달한다.
* Written by: JHP
*********************************************************************************/

#include <vector>
#include <iostream>
#include <memory>

#include "../Observer/Observer.h"

#include "../EventLitener_Defines.h"

class Subject
{
public:
	Subject();
	virtual ~Subject();

	// Register observer
	void Register(Observer* _observer);

	// Unregister observer
	void Unregister(Observer* _observer);

	// notify occured specific event(i.e: E_EVENT_TYPE) to all registered observers
	// Add or delete parameters to suit program purpose
	// 등록된 모든 관찰자에게 이벤트를 알림 (상황에 맞게 파라미터를 추가/삭제하여 사용)
	void Notify(E_EVENT_LISTENER_TYPE eType, CEventListener_Info_Base* sInfo);

protected:
	// vector to manage observer
	std::vector<Observer*> m_vecObserver;
};