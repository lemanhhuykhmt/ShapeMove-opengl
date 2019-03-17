#pragma once
#include "Collider.h"
class BoxCollider : virtual public Collider
{
private: 
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
	bool IsPointInSide(Vector3 point);
	std::vector<Vector3>GetPointsToCheck();
	BoxCollider();
	BoxCollider(Vector3 c, int w, int h, int d);
	~BoxCollider();
};

