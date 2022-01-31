#include"Player.h"
#include"Utils.h"

#include<iostream>

Player::Player(const Vector& pos)
	:Entity(pos), isGround(false), fallSpeed(.2f), jumpHeight(15.f), acceleration(.1f), maxSpeed(3.5f),
	deaccelerate(false), deacceleration(0.05f)
{
	velocity.SetLength(0.f);
}

void Player::Update()
{
	//GRAVITY
	if (!isGround && velocity.GetY() <= 6.f)
		velocity.AddTo(Vector(0.f, fallSpeed));



	if (deaccelerate)
	{
		if (velocity.GetX() > 0.f && velocity.GetX() != 0.f)
		{
			velocity.SubTo(Vector(deacceleration, 0.f));
			if (velocity.GetX() < 0.1f)
				velocity.SetX(0.f);
		}
		
		if (velocity.GetX() < 0.f && velocity.GetX() != 0.f)
		{
			velocity.AddTo(Vector(deacceleration, 0.f));
			if (velocity.GetX() > -0.1f)
				velocity.SetX(0.f);
		}
			
	}

	if (velocity.GetX() > maxSpeed)
		velocity.SetX(maxSpeed);

	if (velocity.GetX() < -maxSpeed)
		velocity.SetX(-maxSpeed);

	Vector pos = GetPosition();
	pos.AddTo(velocity);
	SetPosition(pos);
}

void Player::Collision(Entity& e)
{
	isGround = true;
	Vector pos = Vector(GetPosition().GetX(), e.GetPosition().GetY() - GetCurrentFrame().h);
	SetPosition(pos);
}

void Player::Jump()
{
	velocity.SubTo(Vector(0.f, jumpHeight));
}

void Player::Move(int dir)
{
	deaccelerate = false;
	if (velocity.GetX() <= maxSpeed && velocity.GetX() >= -maxSpeed)
		velocity.AddTo(Vector(acceleration * dir, 0.f));


}

void Player::Collide(Entity& e)
{
	Vector pos = Vector(GetPosition().GetX(), e.GetPosition().GetY() + e.GetCurrentFrame().h);
	SetPosition(pos);

	velocity.SetY(velocity.GetY() * -.5f);
}