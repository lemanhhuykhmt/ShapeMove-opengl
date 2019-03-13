#include "Vector.h"
#include "Math.h"


Vector::Vector(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Vector::setX(float _x)
{
	x = _x;
}

float Vector::getX()
{
	return x;
}

void Vector::setY(float _y)
{
	y = _y;
}

float Vector::getY()
{
	return y;
}

void Vector::setZ(float _z)
{
	z = _z;
}

float Vector::getZ()
{
	return z;
}

float Vector::Magnitude()
{
	return sqrtf(x * x + y * y + z * z);
}

Vector Vector::Add(Vector b)
{
	Vector ret;
	ret.x = this->x + b.x;
	ret.y = this->y + b.y;
	ret.z = this->z + b.z;
	return ret;
}

Vector Vector::Sub(Vector b)
{
	Vector ret;
	ret.x = this->x - b.x;
	ret.y = this->y - b.y;
	ret.z = this->z - b.z;
	return ret;
}

Vector Vector::Mul(float k)
{
	Vector ret;
	ret.x = this->x * k;
	ret.y = this->y * k;
	ret.z = this->z * k;
	return ret;
}

float Vector::DotProduct(Vector b)
{
	return this->x * b.x + this->y * b.y + this->z * b.z;
}

Vector Vector::CrossProduct(Vector b)
{
	Vector ret;
	ret.x = y * b.z - z * b.y;
	ret.y = z * b.x - x * b.z;
	ret.z = x * b.y - y * b.x;
	return ret;
}

float Vector::GetAlpha(Vector b)
{
	float cosAlpha = this->DotProduct(b) / (this->Magnitude() * b.Magnitude());
	return acosf(cosAlpha);
}

void Vector::Normalize()
{
	float len = this->Magnitude();
	x = x / len;
	y /= len;
	z /= len;
}

Vector Vector::Rotate_X(float angle, Vector i)
{
	Vector ret;
	ret.x = x;
	ret.y = i.y + (y - i.y) * cos(angle) - (z - i.z) * sin(angle);
	ret.z = i.z + (y - i.y) * sin(angle) + (z - i.z) * cos(angle);
	return ret;
}

Vector Vector::Rotate_Y(float angle, Vector i)
{
	Vector ret;
	ret.x = i.x + (x - i.x) * cos(angle) + (z - i.z) * sin(angle);
	ret.y = y;
	ret.z = i.z - (x - i.x) * sin(angle) + (z - i.z) * cos(angle);
	return ret;
}

Vector Vector::Rotate_Z(float angle, Vector i)
{
	Vector ret;
	ret.x = i.x + (x - i.x) * cos(angle) + (y - i.y) * sin(angle);
	ret.y = i.y - (x - i.x) * sin(angle) + (y - i.y) * cos(angle);
	ret.z = z;
	return ret;
}

Vector::Vector()
{
	x = y = z = 0.0f;
}


Vector::~Vector()
{
}
