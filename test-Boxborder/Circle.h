#pragma once
#include "Shape.h"
#include "CircleCollider.h"
#include "DEFINE.h"
#include "BorderCollider.h"
class Circle : public Shape
{
protected:
	Vector3 center;
	float radius;
public:
	Vector3 getCenter()
	{
		return center;
	}
	void setCenter(Vector3 _center)
	{
		center = _center;
	}
	float getRadius()
	{
		return radius;
	}
	void setRadius(float r)
	{
		radius = r;
	}
	void Collision(Shape* s);
	void Move(float deltaTime);

	virtual void Draw();
	Circle();
	Circle(Vector3 cen, float r, Vector3 corlor);
	~Circle();
};

