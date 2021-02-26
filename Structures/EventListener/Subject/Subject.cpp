#include "Subject.h"

using namespace std;

Subject::Subject()
{
	
}

Subject::~Subject()
{
	// Release all Shared ptr
	if(m_vecObserver.size())
	{
		std::vector<Observer*>::iterator _iter = m_vecObserver.begin();

		while(_iter != m_vecObserver.end())
		{
			_iter = m_vecObserver.erase(_iter);
		}
	}
}

void Subject::Register(Observer* _observer)
{
	std::vector<Observer*>::iterator _iter = std::find(m_vecObserver.begin(), m_vecObserver.end(), _observer);
	if(_iter == m_vecObserver.end())
	{
		m_vecObserver.push_back(_observer);
	}
	else
	{
		std::cout << "[Subject::Register] _observer already exists." << std::endl;
	}	
}

void Subject::Unregister(Observer* _observer)
{
	std::vector<Observer*>::iterator _iter = std::find(m_vecObserver.begin(), m_vecObserver.end(), _observer);
	if (_iter != m_vecObserver.end())
	{
		m_vecObserver.erase(_iter);
	}
	else
	{
		std::cout << "[Subject::Unregister] failed find _observer." << std::endl;
	}
}

void Subject::Notify(E_EVENT_LISTENER_TYPE eType, CEventListener_Info_Base* sInfo)
{
	vector<Observer*>::iterator _iter = m_vecObserver.begin();

	while(_iter != m_vecObserver.end())
	{
		(*_iter)->onNotify(eType, sInfo);

		_iter++;
	}
}
