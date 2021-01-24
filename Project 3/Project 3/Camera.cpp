#include "Camera.h"

float Camera::x = 0;
float Camera::y = 0;

void Camera::Update(float target, float targetY)
{

	int thresholdX = 540;
	int thresholdY = 360;
	int checkX = target - thresholdX;
	int checkY = targetY - thresholdY;

	if (checkX < 0) x = 0;
	else {
		x = checkX;
	}

	if (checkY < 0) y = 0;
	else {
		y = checkY;
	}
	
}

void Camera::Centering(float target)
{
}
