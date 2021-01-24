#include "Particle.h"
#include "DxLib.h"
#include "math.h"

#define PI 3.1415

Particle::Particle()
{
}

void Particle::Update()
{
}

void Particle::Draw()
{
}

LineParticle::LineParticle(float x, float y, int type)
{
	this->type = type;
	this->angle = GetRand(360);
	this->range = 20;
	int a = GetRand(10) + 5;
	
	switch (this->type) {

	case 0:

		this->x = x + cos(angle * PI / 180) * 100;
		this->y = y + sin(angle * PI / 180) * 100;
	
		this->lengthX = cos(angle * PI / 180) * 10;
		this->lengthY = sin(angle * PI / 180) * 10;

		this->speedX = cos(angle * PI / 180) * a;
		this->speedY = sin(angle * PI / 180) * a;

		break;

	case 1:

		this->x = x + cos(angle * PI / 180) * 500;
		this->y = y + sin(angle * PI / 180) * 500;

		this->lengthX = cos(angle * PI / 180) * 10;
		this->lengthY = sin(angle * PI / 180) * 10;

		this->speedX = cos(angle * PI / 180) * a;
		this->speedY = sin(angle * PI / 180) * a;

		break;

	};
	
	



	
	
}

void LineParticle::Update()
{

	Move();
	
}

void LineParticle::Draw()
{

	DrawLineAA(x, y, x + lengthX, y + lengthY, GetColor(255, 255, 255));
	
}

void LineParticle::Move()
{
	switch (type) {

	case 0:

		x += speedX;
		y += speedY;

		range--;
		
		break;
	case 1:

		x -= speedX;
		y -= speedY;

		range--;
		
		break;
		
	}

	
}
