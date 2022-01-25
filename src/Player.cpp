#include"Player.h"
#include"Utils.h"

#include<iostream>

Player::Player(const Vector& pos)
	:Entity(pos)
{
	velocity.SetLength(0.f);
	gravity.SetLength(0.2f);
	gravity.SetAngle(utils::DegreesToRads(90.f));
}

void Player::Update()
{
	//velocity.AddTo(gravity);

	int x, y;

	SDL_GetMouseState(&x, &y);

	SetPosition(Vector(x, y));

	Vector pos = GetPosition();
	pos.AddTo(velocity);

	SetPosition(pos);
}