#pragma once
#include "Player.h"
#include "Object.h"
#include "Enemy.h"
#include "Camera.h"
#include "Collision.h"
#include <vector>

class Scene
{

public:

	Scene();
	void Load();
	void Update();
	
private:

	
	
	Player* player;

	std::vector<Enemy*> enemys;
	std::vector<Object*> objects;

	Collision* collision;

	bool isStart;

};

