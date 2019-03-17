#pragma once
#include"Collider.h"
#include <string>
#include "GL/glut.h"
class Shape
{
protected :
	Vector3 color;
	Vector3 velocity;
	Collider *collider;
	std::string tag;
	
public:

	Shape();
	Shape(Vector3 col);
	virtual ~Shape();
	Vector3 getColor()
	{
		return color;
	}
	void setColor(Vector3 c)
	{
		color = c;
	}
	std::string getTag()
	{
		return tag;

	}
	void setTag(std::string s)
	{
		tag = s;
	}
	Vector3 getVelocity()
	{
		return velocity;
	}
	void setVelocity(Vector3 v)
	{
		velocity = v;
	}
	Collider* getCollider()
	{
		return collider;
	}
	void setCollider(Collider* b)
	{
		collider = b;
	}
	virtual void Collision(Shape* s);
	virtual bool IsCollision(Shape *s);
	virtual void Move(float deltaTime) =0;

	///
	virtual void Draw() = 0;
};

