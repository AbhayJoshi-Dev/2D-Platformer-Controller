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
	if(velocity.GetY() <= 5.f)
		velocity.AddTo(gravity);


	Vector pos = GetPosition();
	pos.AddTo(velocity);

	SetPosition(pos);

	std::cout << velocity.GetX() << ", " << velocity.GetY() << std::endl;
}

void Player::Collision(Entity& e)
{
	Vector pos = Vector(GetPosition().GetX(), e.GetPosition().GetY() - GetCurrentFrame().h);
	SetPosition(pos);
}

void Player::Jump()
{
	velocity.SubTo(Vector(0.f, 10.f));
	velocity.SetX(0.f);
}