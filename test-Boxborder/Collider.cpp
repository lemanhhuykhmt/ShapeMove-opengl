#include "Collider.h"

Collider::Collider()
{
}


Collider::~Collider()
{
}

bool Collider::IsCollsion(Collider &c)
{
	std::vector<Vector3> points = c.GetPointsToCheck();
	for (auto i = 0; i < points.size(); ++i)
	{
		if (IsPointInSide(points[i]))
		{
			return true;
		}
	}
	return false;
}
