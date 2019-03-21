#pragma once
#include "Vector3.h"
#include <vector>
#include <iostream>
#include <GL/glut.h>

class Collider
{
protected: 

	Vector3 pointInner;
	std::vector<Vector3> listPoints;

public:
	bool Using;
	 Collider();
	~Collider();
	Vector3 getPointInner()
	{
		return pointInner;
	}
	void setPointInner(Vector3 value)
	{
		pointInner = value;
	}
	virtual std::vector<Vector3> GetPointsToCheck();
	virtual bool IsPointInSide(Vector3 point) =0;
	virtual bool IsCollsion(Collider &c);
	virtual void Move(Vector3 deltaMove);
	void Draw();
};

