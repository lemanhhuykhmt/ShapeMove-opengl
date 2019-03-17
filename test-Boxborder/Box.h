#pragma once
#include"BoxCollider.h"
class Box
{
private:
	Vector3 center;
	int width, height, depth;
	BoxCollider *collider;
	Vector3 velocity;
public:
	Vector3 getCenter()
	{
		return center;
	}
	void setCenter(Vector3 _center)
	{
		center = _center;
	}
	int getWidth()
	{
		return width;
	}
	void setWidth(int w)
	{
		width = w;
	}
	int getHeight()
	{
		return height;
	}
	void setHeight(int h)
	{
		height = h;
	}
	int getDepth()
	{
		return depth;
	}
	void setDepth(int d)
	{
		depth = d;
	}
	BoxCollider* getCollider()
	{
		return collider;
	}
	void setCollider(BoxCollider* b)
	{
		collider = b;
	}
	Vector3 getVelocity()
	{
		return velocity;
	}
	void setVelocity(Vector3 v)
	{
		velocity = v;
	}
	Box();
	~Box();
};

