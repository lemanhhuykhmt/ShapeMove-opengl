#include "BoxCollider.h"



bool BoxCollider::IsPointInSide(Vector3 point)
{
	Vector3 min(center.getX() - width / 2.0, center.getY() - height / 2.0, center.getZ() - depth / 2.0);
	Vector3 max(center.getX() + width / 2.0, center.getY() + height / 2.0, center.getZ() + depth / 2.0);
	if (point.getX() >= min.getX() && point.getX() <= max.getX() &&
		point.getY() >= min.getY() && point.getY() <= max.getY() &&
		point.getZ() >= min.getZ() && point.getZ() <= max.getZ())
	{
		return true;
	}
	return false;

	return false;
}

std::vector<Vector3> BoxCollider::GetPointsToCheck()
{
	Vector3 min(center.getX() - width / 2.0, center.getY() - height / 2.0, center.getZ() - depth / 2.0);
	Vector3 max(center.getX() + width / 2.0, center.getY() +height / 2.0, center.getZ()  + depth / 2.0);
	//
	std::vector<Vector3> listPoints(8);
	listPoints[0] = Vector3(min.getX(), min.getY(), min.getZ());
	listPoints[1] = Vector3(min.getX(), max.getY(), min.getZ());
	listPoints[2] = Vector3(max.getX(), max.getY(), min.getZ());
	listPoints[3] = Vector3(max.getX(), min.getY(), min.getZ());
	listPoints[4] = Vector3(min.getX(), min.getY(), max.getZ());
	listPoints[5] = Vector3(min.getX(), max.getY(), max.getZ());
	listPoints[6] = Vector3(max.getX(), max.getY(), max.getZ());
	listPoints[7] = Vector3(max.getX(), min.getY(), max.getZ());

	return listPoints;
}

BoxCollider::BoxCollider()
{
}

BoxCollider::BoxCollider(Vector3 c, int w, int h, int d)
{
	center = c;
	width = w;
	height = h;
	depth = d;
}


BoxCollider::~BoxCollider()
{
}
