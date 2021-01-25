#include "Player.h"
#include "Constant.h"
#include "DxLib.h"
#include "Scene.h"

Player::Player(float x, float y, int size)
{

	this->x = x;
	this->y = y;
	this->size = size;
	backGraph = LoadGraph("Images/back.png");
	frontGraph = LoadGraph("Images/front.png");
	graph = LoadGraph("Images/rocket.png");
	
}

void Player::Update()
{

	InputProcessing();

	for(int i = 0; i < objects.size(); i++) {
		CollisionProcess(objects[i]);
	}
	/*for (int i = 0; i < enemies.size(); i++) {
		CollisionProcess(enemies[i]);
	}*/

}

void Player::Draw()
{

	float cam = Camera::GetX();
	float camY = Camera::GetY();

	if(LoopHole::GetLoopIn()) {

		DrawExtendGraph(x - size - cam, y - size - camY, x + size - cam, y + size - camY, backGraph, true);
		
	}
	else if(LoopHole::GetLoopOut()) {

		DrawExtendGraph(x - size - cam, y - size - camY, x + size - cam, y + size - camY, frontGraph, true);
		
	}
	else {

		DrawExtendGraph(x - size - cam, y - size - camY, x + size - cam, y + size - camY, graph, true);
		
	}
	
	
	
}

void Player::InputProcessing()
{

	if (Input::isKey(KEY_INPUT_D)) {
		x += 100 * DELTATIME;
	}

	if (Input::isKey(KEY_INPUT_A)) {
		x -= 5;
	}

	if (Input::isKey(KEY_INPUT_W)) {
		y -= 5;
	}

	if (Input::isKey(KEY_INPUT_S)) {
		y += 5;
	}

	if (LoopHole::CanTeleport()) {

		x = LoopHole::GetTeleX();
		y = LoopHole::GetTeleY();
		LoopHole::TeleportDone();

	}
	
}

template <typename T>
void Player::CollisionProcess(T* objects)
{

	float rangeX = x - objects->GetX();
	float rangeY = y - objects->GetY();
	int _size = objects->GetSize();

	float calc = (rangeX * rangeX) + (rangeY * rangeY);
	float _size2 = _size * _size;
	
	if(calc < _size2 ) {

		objects->OnCollision();
		
	}

}

void Player::LoadObjects(std::vector<Object*> object)
{

	this->objects = object;
	
}

void Player::LoadEnemies(std::vector<Enemy*> enemy)
{

	this->enemies = enemy;
	
}
