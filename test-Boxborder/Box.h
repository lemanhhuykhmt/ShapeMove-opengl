#pragma once
#include "BorderCollider.h"
#include"BoxCollider.h"
#include "Shape.h"
#include "DEFINE.h"
class Box : public Shape
{
protected:
	Vector3 center;
	int width, height, depth;
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
	void Collision(Shape* s);
	void Move(float deltaTime);


	//opengl
	void Draw();
	Box();
	Box(Vector3 cen, int w, int h, int d, Vector3 corlor);
	~Box();
};

