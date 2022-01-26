#pragma once

#include"Entity.h"

class Player : public Entity
{
private:
	Vector velocity;
	Vector gravity;
public:
	Player(const Vector& pos);
	void Update();
	void Collision(Entity& e);
	void Jump();
};