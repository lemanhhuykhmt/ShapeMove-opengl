#pragma once
#include"Collider.h"
class CircleCollider : public Collider
{
private:
	Vector3 center;
	float radius;
	const int slices = 10;
	const int stacks = 10;
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
	bool IsPointInSide(Vector3 point);
	std::vector<Vector3>GetPointsToCheck();
	CircleCollider();
	CircleCollider(Vector3 c, float r);
	~CircleCollider();
};

