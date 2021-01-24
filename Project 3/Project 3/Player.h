#pragma once
#include "Input.h"
#include "Object.h"
#include "Enemy.h"
#include "Camera.h"
#include <vector>

class Player
{

public:

	Player(float x, float y, int size);
	void Update();
	void Draw();
	void InputProcessing();
	template <typename T>
	void CollisionProcess(T* objects);
	void LoadObjects(std::vector<Object*> object);
	void LoadEnemies(std::vector<Enemy*> enemy);

	float GetX() { return x; }
	float GetY() { return y; }
	
private:

	float x;
	float y;
	int size;

	int backGraph;
	int frontGraph;
	int graph;
	std::vector<Object*> objects;
	std::vector<Enemy*> enemies;
	
};

