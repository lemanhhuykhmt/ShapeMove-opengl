#pragma once
class Vector
{
private:
	float x;
	float y;
	float z;
public:
	Vector(float _x, float _y, float _z);
	void setX(float _x);
	float getX();
	void setY(float _y);
	float getY();
	void setZ(float _z);
	float getZ();
	float Magnitude();
	Vector Add(Vector b);
	Vector Sub(Vector b);
	Vector Mul(float k);
	float DotProduct(Vector b);
	Vector CrossProduct(Vector b);
	float GetAlpha(Vector b);
	void Normalize();

	Vector Rotate_X(float angle, Vector i);
	Vector Rotate_Y(float angle, Vector i);
	Vector Rotate_Z(float angle, Vector i);
	Vector();
	~Vector();
};

