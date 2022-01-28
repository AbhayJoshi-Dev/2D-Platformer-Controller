#pragma once

#include"Entity.h"

class Player : public Entity
{
private:
	Vector velocity;
	float fallSpeed;
	float jumpHeight;
	float acceleration;
	float maxSpeed;
	float deacceleration;

public:
	bool isGround;
	bool deaccelerate;
	Player(const Vector& pos);
	void Update();
	void Collision(Entity& e);
	void Jump();
	void Move(int dir);
};