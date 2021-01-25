#include "Collision.h"
#include "DxLib.h"

Collision::Collision()
{
}

void Collision::PlayerToEnemy(Player* player, Enemy* enemy)
{

	float x = player->GetX();
	float y = player->GetY();

	Enemy* obj = new Enemy();
	if (obj = dynamic_cast<PatrolEnemy*>(enemy))
	{

		

		bool checkPlayer = enemy->CheckPlayer(x, y);

		if (checkPlayer)
		{
			enemy->OnCollision();
		}



	}
	else if (obj = dynamic_cast<ExplodingEnemy*>(enemy))
	{

		float rangeX = x - enemy->GetX();
		DrawFormatString(0, 40, GetColor(255, 0, 0), "%f", enemy->GetX());
		float rangeY = y - enemy->GetY();
		int _size = enemy->GetSize();

		float calc = (rangeX * rangeX) + (rangeY * rangeY);
		float _size2 = _size * _size;

		if (calc < _size2) {

			enemy->OnCollision();

		}
	}






}

void Collision::PlayerToObject(Player* player, Object* object)
{
}
