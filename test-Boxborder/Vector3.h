#pragma once
class Vector3
{
private:
	float x;
	float y;
	float z;
public:
	Vector3();
	Vector3(float _x, float _y, float _z);
	Vector3(const Vector3& v);
	void setX(float _x);
	float getX();
	void setY(float _y);
	float getY();
	void setZ(float _z);
	float getZ();
	float Magnitude();
	Vector3 Add(Vector3 b);
	Vector3 Sub(Vector3 b);
	Vector3 Mul(float k);
	float DotProduct(Vector3 b);
	Vector3 CrossProduct(Vector3 b);
	float GetAlpha(Vector3 b);
	void Normalize();
	////
	Vector3 operator+(const Vector3& v);
	Vector3& operator+=(const Vector3& v);
	Vector3 operator-();
	Vector3 operator-(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3 operator*(const float s);
	Vector3 operator/(const float s);
	float operator*(const Vector3& v);
	Vector3 operator^(const Vector3& v);
	bool operator==(const Vector3& v);
	bool operator!=(const Vector3& v);

	////
	Vector3 Rotate_X(float angle, Vector3 i);
	Vector3 Rotate_Y(float angle, Vector3 i);
	Vector3 Rotate_Z(float angle, Vector3 i);
	~Vector3();
};

