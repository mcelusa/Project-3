#pragma once
class Camera
{

public:

	static float GetX() { return x; }
	static float GetY() { return y; }
	static void Update(float target, float targetY);
	static void Centering(float target);
	
private:
	
	static float x;
	static float y;
	static bool toCenter;
	
	
};

