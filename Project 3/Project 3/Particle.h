#pragma once
class Particle
{

public:

	Particle();
	virtual void Update();
	virtual void Draw();

	int GetRange() { return range; }
	
protected:

	float x;
	float y;
	float speedX;
	float speedY;
	float angle;

	int range;
	
	
};

class LineParticle : public Particle {

public:
	
	LineParticle(float x, float y, int type);
	void Update() override;
	void Draw() override;
	void Move();

	
	
private:

	float lengthX;
	float lengthY;

	int type;
	
};
