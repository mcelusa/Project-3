#pragma once
#include "Object.h"

class Enemy
{

public:

	Enemy();
	virtual void Update();
	virtual void Draw();
	virtual void OnCollision();

	float GetX() { return x; }
	float GetY() { return y; }
	float GetSize() { return collisionRange; }
	
protected:

	float x;
	float y;
	int size;
	int graph;
	float sizeRate;
	float angle;
	float collisionRange;
	
};

class ExplodingEnemy : public Enemy {

public:

	ExplodingEnemy(float x, float y);
	void Update() override;
	void Draw() override;
	void OnCollision() override;
	
	
private:
	int flipSpeed;
	bool flipUp;
	int flipCount;
	bool countDownState;
	int countDown;
	Object* object;
	bool isDead;
	
};

