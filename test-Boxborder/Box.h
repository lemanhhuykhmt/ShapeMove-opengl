#pragma once
#include "BorderCollider.h"
#include"BoxCollider.h"
#include "Shape.h"
#include "DEFINE.h"
class Box : public Shape
{
protected:
	Vector3 center;
	float width, height, depth;
public:
	Vector3 getCenter()
	{
		return center;
	}
	void setCenter(Vector3 _center)
	{
		center = _center;
	}
	float getWidth()
	{
		return width;
	}
	void setWidth(float w)
	{
		width = w;
	}
	float getHeight()
	{
		return height;
	}
	void setHeight(float h)
	{
		height = h;
	}
	float getDepth()
	{
		return depth;
	}
	void setDepth(float d)
	{
		depth = d;
	}
	void Collision(Shape* s);
	void Move(float deltaTime);


	//opengl
	virtual void Draw();
	Box();
	Box(Vector3 cen, float w, float h, float d, Vector3 corlor);
	~Box();
};

