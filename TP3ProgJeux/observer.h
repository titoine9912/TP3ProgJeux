#pragma once
#include "enemy.h"
class observer : public enemy
{
public :
	observer();
	virtual void notify() = 0;



};