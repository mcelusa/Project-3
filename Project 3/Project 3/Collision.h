#pragma once
#include "Player.h"
#include "Object.h"
#include "Enemy.h"

class Collision
{

public:
	
	Collision();
	void PlayerToEnemy(Player *player, Enemy* enemy);
	void PlayerToObject(Player* player, Object* object);

private:



};

