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

bool Enemy::CheckPlayer(float targetX, float targetY)
{
	return false;
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

PatrolEnemy::PatrolEnemy(float x, float y)
{

	this->x = x;
	this->y = y;
	this->size = 20;
	this->angle = 0;
	this->graph = LoadGraph("Images/Enemy.png");
	line1 = new Line(x, y, angle + 30);
	line2 = new Line(x, y, angle - 30);
	playerInRange = false;

}

void PatrolEnemy::Update()
{
	if (!playerInRange)
	{
		angle += 30 * DELTATIME;
		if (angle > 360 * PI)
		{
			angle = 0;
		}
	}
	

	line1->SetAngle(angle + 30);
	line2->SetAngle(angle - 30);
	line1->Update();
	line2->Update();

	

}

void PatrolEnemy::Draw()
{

	float cam = Camera::GetX();
	float camY = Camera::GetY();

	DrawRotaGraph(x- cam, y - camY, 0.5, angle, graph, true);

	if (playerInRange)
	{
		SetDrawBright(255, 0, 0);
		DrawRotaGraph(x - cam, y - camY, 0.5, angle * PI / 180, graph, true);
		SetDrawBright(255, 255, 255);
	}

	line1->Draw();
	line2->Draw();



}

bool PatrolEnemy::CheckPlayer(float targetX, float targetY)
{

	if (CheckLine1(targetX, targetY) && CheckLine2(targetX, targetY))
	{
		return true;
	}
		

}

bool PatrolEnemy::CheckLine1(float targetX, float targetY)
{
	
	float a = (targetX - line1->GetX()) * (line1->GetY1() - line1->GetY());
	float b = (targetY - line1->GetY()) * (line1->GetX1() - line1->GetX());
	float c = a - b;
	DrawFormatString(0, 60, GetColor(255, 0, 0), "%f", c);
	if (c > 0) return true;
}

bool PatrolEnemy::CheckLine2(float targetX, float targetY)
{
	float a = (targetX - line2->GetX()) * (line2->GetY1() - line2->GetY());
	float b = (targetY - line2->GetY()) * (line2->GetX1() - line2->GetX());
	float c = a - b;
	DrawFormatString(0, 80, GetColor(255, 0, 0), "%f", c);
	if (c < 0) return true;
}

void PatrolEnemy::OnCollision()
{
	playerInRange = true;
}


Line::Line(float x, float y, float angle)
{

	this->x = x;
	this->y = y;
	
	this->angle = angle;

	this->x1 = x + cos(angle * PI / 180) * 500;
	this->y1 = y + sin(angle * PI / 180) * 500;

}

void Line::Draw()
{


	float cam = Camera::GetX();
	float camY = Camera::GetY();

	DrawLineAA(x - cam, y - camY, x1 - cam, y1 - camY, GetColor(255, 255, 255));

}

void Line::Update()
{

	x1 = x + cos(angle * PI / 180) * 500;
	y1 = y + sin(angle * PI / 180) * 500;

}

void Line::SetAngle(float angle)
{

	this->angle = angle;

}
