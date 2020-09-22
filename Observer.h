#pragma once

class Observer
{
	virtual ~Observer();

	virtual void onNotify(const Entity& entity, Event evet) = 0;
}
