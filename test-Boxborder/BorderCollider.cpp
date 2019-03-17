#include "BorderCollider.h"



BorderCollider::BorderCollider()
{
}

BorderCollider::BorderCollider(Vector3 c, int w, int h, int d) : BoxCollider(c, w, h, d)
{
}


BorderCollider::~BorderCollider()
{
}

bool BorderCollider::IsCollsion(Collider & c)
{
	std::vector<Vector3> points = c.GetPointsToCheck();
	for (auto i = 0; i < points.size(); ++i)
	{
		if (!IsPointInSide(points[i]))
		{
			return true;
		}
	}
	return false;
}

DEFINE::EDirection BorderCollider::DirectionCollision(Collider & c)
{
	Vector3 minBorder(center.getX() - width / 2.0, center.getY() - height / 2.0, center.getZ() - depth / 2.0);
	Vector3 maxBorder(center.getX() + width / 2.0, center.getY() + height / 2.0, center.getZ() + depth / 2.0);
	std::vector<Vector3> points = c.GetPointsToCheck();
	for (int i = 0; i < points.size(); ++i)
	{
		if (points[i].getX() <= minBorder.getX())
			return DEFINE::EDirection::LEFT;
		if (points[i].getX() >= maxBorder.getX())
			return DEFINE::EDirection::RIGHT;
		if (points[i].getY() <= minBorder.getY())
			return DEFINE::EDirection::BOTTOM;
		if (points[i].getY() >= maxBorder.getY())
			return DEFINE::EDirection::TOP;
		if (points[i].getZ() <= minBorder.getZ())
			return DEFINE::EDirection::BACK;
		if (points[i].getZ() >= maxBorder.getZ())
			return DEFINE::EDirection::FRONT;
	}
	return DEFINE::EDirection();
}
