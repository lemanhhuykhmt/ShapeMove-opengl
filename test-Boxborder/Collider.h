#pragma once
#include "Vector3.h"
#include <vector>
#include <iostream>

class Collider
{
private: 

	Vector3 pointInner;
	

public:
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
	virtual std::vector<Vector3> GetPointsToCheck() =0;
	virtual bool IsPointInSide(Vector3 point) =0;
	bool IsCollsion(Collider &c);
};

