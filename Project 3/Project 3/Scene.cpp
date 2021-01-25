#include "Scene.h"

#include <DxLib.h>


Scene::Scene()
{

	isStart = false;
	
}

void Scene::Update()
{

	if(!isStart) {
		Load();
		isStart = true;
	}

	Input::Update();
	Camera::Update(player->GetX(), player->GetY());
	
	player->Update();
	for (int i = 0; i < enemys.size(); i++) enemys[i]->Update();
	for (int i = 0; i < objects.size(); i++) objects[i]->Update();
	for (int i = 0; i < enemys.size(); i++) collision->PlayerToEnemy(player, enemys[i]);
	

	for (int i = 0; i < enemys.size(); i++) enemys[i]->Draw();
	for (int i = 0; i < objects.size(); i++) objects[i]->Draw();
	player->Draw();
}

void Scene::Load()
{

	
	objects.push_back(new LoopHole(2400, 2400, 2900, 1500));
	objects.push_back(new LoopHole(2200, 2200, 2500, 1100));
	objects[0]->Connect(objects[1]);
	objects[1]->Connect(objects[0]);
	//objects.push_back(new Bomb(100, 400));
	enemys.push_back(new ExplodingEnemy(2400, 1800));
	enemys.push_back(new ExplodingEnemy(2000, 1800));
	enemys.push_back(new PatrolEnemy(2000, 1600));
	player = new Player(2000, 2000, 30);

	collision = new Collision();

	player->LoadObjects(objects);
	player->LoadEnemies(enemys);
	
}
