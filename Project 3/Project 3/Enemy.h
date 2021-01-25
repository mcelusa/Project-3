#pragma once
#include "Object.h"
#include "Constant.h"

class Player;

class Enemy
{

public:

	Enemy();
	virtual void Update();
	virtual void Draw();
	virtual void OnCollision();
	virtual bool CheckPlayer(float targetX, float targetY);

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

class Line
{

public:

	Line(float x, float y, float angle);
	void Draw();
	void Update();
	void SetAngle(float angle);

	float GetX() { return x; }
	float GetY() { return y; }
	float GetX1() { return x1; }
	float GetY1() { return y1; }

	float GetAngle() { return angle; }

private:

	float x;
	float x1;
	float y;
	float y1;
	float angle;

};

class PatrolEnemy : public Enemy
{

public:

	PatrolEnemy(float x, float y);
	void Update() override;
	void Draw() override;
	bool CheckPlayer(float targetX, float targetY) override;
	bool CheckLine1(float targetX, float targetY);
	bool CheckLine2(float targetX, float targetY);
	void OnCollision() override;

private:

	bool playerInRange;
	Line* line1;
	Line* line2;

};