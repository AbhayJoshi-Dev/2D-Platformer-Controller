#include<cmath>

#include"Vector.h"

Vector::Vector(float p_x, float p_y)
	:x(p_x), y(p_y)
{}

float Vector::GetX() const
{
	return x;
}

void Vector::SetX(float value)
{
	x = value;
}

float Vector::GetY() const
{
	return y;
}

void Vector::SetY(float value)
{
	y = value;
}

float Vector::GetAngle() const
{
	return std::atan2(y, x);
}

void Vector::SetAngle(float angle)
{
	float length = GetLength();

	x = std::cos(angle) * length;
	y = std::sin(angle) * length;
}

float Vector::GetLength() const
{
	return std::sqrt(x * x + y * y);
}

void Vector::SetLength(float len)
{
	float angle = GetAngle();

	x = std::cos(angle) * len;
	y = std::cos(angle) * len;
}

void Vector::AddTo(const Vector& v)
{
	x += v.x;
	y += v.y;
}

void Vector::SubTo(const Vector& v)
{
	x -= v.x;
	y -= v.y;
}

void Vector::Scale(float factor)
{
	x *= factor;
	y *= factor;
}

void Vector::Scale(float x, float y)
{
	x *= x;
	y *= y;
}

float Vector::Dot(const Vector& other) const
{
	return (x * other.x + y * other.y);
}

Vector& Vector::Unitize()
{
	float mag = GetLength();

	if (mag != 0)
	{
		x /= mag;
		y /= mag;
	}

	return *this;
}

Vector Vector::Unit() const
{
	float mag = GetLength();

	if (mag == 0)
	{
		return Vector();
	}
	else
	{
		return Vector(x / mag, y / mag);
	}
}

Vector Vector::operator+(const Vector& other) const
{
	return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector& other) const
{
	return Vector(x - other.x, y - other.y);
}

Vector Vector::Subtract(const Vector& v)
{
	return Vector(x - v.GetX(), y - GetY());
}

Vector Vector::Multiply(float value)
{
	return Vector(x * value, y * value);
}