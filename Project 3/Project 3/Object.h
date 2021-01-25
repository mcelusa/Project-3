#pragma once
#include "Particle.h"
#include "Constant.h"
#include <vector>

using namespace std;

class Object
{

public:

	Object();
	virtual void Update();
	virtual void Draw();
	virtual void OnCollision();
	virtual void Start();
	virtual void Connect(Object* loopHole);

	float GetX() { return x; }
	float GetY() { return y; }
	float GetSize() { return size; }

	void SetX(float x);
	void SetY(float y);

	float GetSizeRate() { return sizeRate; }
	
protected:
	
	float x;
	float y;
	float angle;
	int size;

	float sizeRate;

	
};

class LoopHole : public Object {

public:

	LoopHole(float x, float y, int nextX, int nextY);
	void Update() override;
	void Draw() override;
	void OnCollision() override;
	void Start() override;
	void Connect(Object* loopHole) override;
	
	static bool CanTeleport() { return teleportPlayer; }
	static int GetTeleX() { return teleX; }
	static int GetTeleY() { return teleY; }
	static void TeleportDone();
	static float GetSizeRateChange() { return sizeRateChange; }
	static bool GetLoopIn() { return loopIn; }
	static bool GetLoopOut() { return loopOut; }
	static float GetLoopX() { return loopX; }
	static float GetLoopY() { return loopY; }

private:

	int nextX;
	int nextY;
	
	bool isLoop;
	int graph;
	int lineGraph;
	int flipValue;
	int frame;
	bool flipOn;

	int rotateSpeed;

	static bool teleportPlayer;
	static int teleX;
	static int teleY;
	static float sizeRateChange;
	static bool loopIn;
	static bool loopOut;
	static float loopX;
	static float loopY;

	Object* loopHole;
	vector<Particle*> particle;
};

class Bomb : public Object {

public:

	Bomb(float x, float y);
	void Update() override;
	void Draw() override;
	void OnCollision() override;
	
private:

	bool isExplode;
	
};

class Explosion : public Object {

public:

	Explosion(float x, float y);
	void Update();
	void Draw();

private:

	int frame;
	int graph[6];
	int graphNum;
	
};
