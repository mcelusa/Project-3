#include "Enemy.h"
#include "Object.h"
#include "Camera.h"
#include "DxLib.h"

Enemy::Enemy()
{
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
}

void Enemy::OnCollision()
{
}

ExplodingEnemy::ExplodingEnemy(float x, float y)
{

	this->x = x;
	this->y = y;
	this->size = 20;
	this->sizeRate = 0.5;
	this->angle = 0;
	collisionRange = 200;
	countDownState = false;
	flipCount = 0;
	graph = LoadGraph("Images/Enemy.png");
	isDead = false;
	countDown = 180;
	flipUp = true;
	flipSpeed = 20;
}

void ExplodingEnemy::Update()
{

	if(LoopHole::GetLoopIn()) {
		sizeRate += LoopHole::GetSizeRateChange();
	}
	else if(LoopHole::GetLoopOut()){
		if(sizeRate > 0.5f) {
			sizeRate -= LoopHole::GetSizeRateChange();
		}
	}
	if(object != nullptr) {
		object->Update();
	}

	if (countDownState) {

		if (countDown > 0) {

			countDown--;

		}
		else {

			if (!isDead) {
				object = new Explosion(x, y);
				isDead = true;
			}

			countDown = 0;

		}

	}
	
}

void ExplodingEnemy::Draw()
{

	float rateX;
	float rateY;
	
	if(LoopHole::GetLoopIn()) {
		rateX = (x - LoopHole::GetLoopX()) * sizeRate;
		rateY = (y - LoopHole::GetLoopY()) * sizeRate;
	}
	else if(LoopHole::GetLoopOut()){

		
		rateX = (x - LoopHole::GetTeleX()) * sizeRate;
		rateY = (y - LoopHole::GetTeleY()) * sizeRate;
		
	}
	else {
		rateX = 0;
		rateY = 0;
	}
	
	float cam = Camera::GetX();
	float camY = Camera::GetY();

	if(!isDead) {

		DrawRotaGraph(x - cam + rateX, y - camY + rateY, sizeRate, angle, graph, true);
		DrawBox(x - size - cam, y - size - camY, x + size - cam, y + size - camY, GetColor(0, 255, 0), false);

		if (countDownState) {

			if (flipUp) {
				flipCount += flipSpeed;

				if (flipCount > 255) {
					flipUp = false;
					flipSpeed += 10;
				}
			}
			else {

				flipCount -= flipSpeed;
				if (flipCount < 0) {
					flipUp = true;
					flipSpeed += 10;
				}

			}



			SetDrawBright(255, 0, 0);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, flipCount);
			DrawRotaGraph(x - cam + rateX, y - camY + rateY, sizeRate, angle, graph, true);
			SetDrawBright(255, 255, 255);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		}

	}

	if (object != nullptr) {
		object->Draw();
	}

	if(countDownState) {

		int q = countDown / 60;
		DrawFormatString(x - 10 - cam, y - size - 70 - camY, GetColor(255, 0, 0), "%d", q + 1);
		
	}

	if(countDownState) {

		if(countDown > 0) {

			countDown--;
			
		}
		else {

			if (!isDead) {
				object = new Explosion(x, y);
				isDead = true;
			}
			
			countDown = 0;
			
		}
		
	}
	
	
}

void ExplodingEnemy::OnCollision()
{
	if(!countDownState) {

		countDownState = true;
		
	}

	
	
	

	
}


