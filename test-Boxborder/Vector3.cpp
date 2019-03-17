#include "Vector3.h"
#include "Math.h"


Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3::Vector3(const Vector3 & v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

void Vector3::setX(float _x)
{
	x = _x;
}

float Vector3::getX()
{
	return x;
}

void Vector3::setY(float _y)
{
	y = _y;
}

float Vector3::getY()
{
	return y;
}

void Vector3::setZ(float _z)
{
	z = _z;
}

float Vector3::getZ()
{
	return z;
}

float Vector3::Magnitude()
{
	return sqrtf(x * x + y * y + z * z);
}

Vector3 Vector3::Add(Vector3 b)
{
	Vector3 ret;
	ret.x = this->x + b.x;
	ret.y = this->y + b.y;
	ret.z = this->z + b.z;
	return ret;
}

Vector3 Vector3::Sub(Vector3 b)
{
	return Vector3(x - b.x, y - b.y, z - b.z);
}

Vector3 Vector3::Mul(float s)
{
	return Vector3(x * s, y * s, z * s);
}

float Vector3::DotProduct(Vector3 b)
{
	return this->x * b.x + this->y * b.y + this->z * b.z;
}

Vector3 Vector3::CrossProduct(Vector3 b)
{
	Vector3 ret;
	ret.x = y * b.z - z * b.y;
	ret.y = z * b.x - x * b.z;
	ret.z = x * b.y - y * b.x;
	return ret;
}

float Vector3::GetAlpha(Vector3 b)
{
	float cosAlpha = this->DotProduct(b) / (this->Magnitude() * b.Magnitude());
	return acosf(cosAlpha);
}

void Vector3::Normalize()
{
	float len = this->Magnitude();
	x = x / len;
	y /= len;
	z /= len;
}

Vector3 Vector3::operator+(const Vector3& v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 & Vector3::operator+=(const Vector3 & v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3 Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator-(const Vector3 & v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 & Vector3::operator-=(const Vector3 & v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3 Vector3::operator*(const float s)
{
	return Vector3(x * s, y * s, z * s);
}

Vector3 Vector3::operator/(const float s)
{
	return Vector3(x / s, y / s, z / s);
}

float Vector3::operator*(const Vector3& v)
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::operator^(const Vector3& v)
{
	Vector3 ret;
	ret.x = y * v.z - z * v.y;
	ret.y = z * v.x - x * v.z;
	ret.z = x * v.y - y * v.x;
	return ret;
}

Vector3 Vector3::Rotate_X(float angle, Vector3 i)
{
	Vector3 ret;
	ret.x = x;
	ret.y = i.y + (y - i.y) * cos(angle) - (z - i.z) * sin(angle);
	ret.z = i.z + (y - i.y) * sin(angle) + (z - i.z) * cos(angle);
	return ret;
}

Vector3 Vector3::Rotate_Y(float angle, Vector3 i)
{
	Vector3 ret;
	ret.x = i.x + (x - i.x) * cos(angle) + (z - i.z) * sin(angle);
	ret.y = y;
	ret.z = i.z - (x - i.x) * sin(angle) + (z - i.z) * cos(angle);
	return ret;
}

Vector3 Vector3::Rotate_Z(float angle, Vector3 i)
{
	Vector3 ret;
	ret.x = i.x + (x - i.x) * cos(angle) + (y - i.y) * sin(angle);
	ret.y = i.y - (x - i.x) * sin(angle) + (y - i.y) * cos(angle);
	ret.z = z;
	return ret;
}

Vector3::Vector3()
{
	x = y = z = 0.0f;
}


Vector3::~Vector3()
{
}
