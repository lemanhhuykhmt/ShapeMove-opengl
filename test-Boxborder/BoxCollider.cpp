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
	if (listPoints.size() != 0) return listPoints;
	Vector3 min(center.getX() - width / 2.0, center.getY() - height / 2.0, center.getZ() - depth / 2.0);
	Vector3 max(center.getX() + width / 2.0, center.getY() +height / 2.0, center.getZ()  + depth / 2.0);
	//
	int numberW = (int)ceilf(width);
	int numberH = (int)ceilf(height);
	int numberD = (int)ceilf(depth);

	float deltaWidth = width / numberW;
	float deltaHeight = height / numberH;
	float deltaDepth = depth / numberD;
	// front and back
	for (int i = 0; i <= numberW; ++i)
	{
		for (int j = 0; j <= numberH; ++j)
		{
			listPoints.push_back(Vector3(min.getX() + i * deltaWidth, min.getY() + j * deltaHeight, min.getZ()));
			listPoints.push_back(Vector3(min.getX() + i * deltaWidth, min.getY() + j * deltaHeight, max.getZ()));
		}
	}
	// left and right
	for (int i = 0; i <= numberD; ++i)
	{
		for (int j = 0; j <= numberH; ++j)
		{
			listPoints.push_back(Vector3(min.getX(), min.getY() + j * deltaHeight, min.getZ() + i * deltaDepth));
			listPoints.push_back(Vector3(max.getX(), min.getY() + j * deltaHeight, min.getZ() + i * deltaDepth));
		}
	}
	// top and bottom
	for (int i = 0; i <= numberW; ++i)
	{
		for (int j = 0; j <= numberD; ++j)
		{
			listPoints.push_back(Vector3(min.getX() + i * deltaWidth, min.getY(), min.getZ() + j * deltaDepth));
			listPoints.push_back(Vector3(min.getX() + i * deltaWidth, max.getY(), min.getZ() + j * deltaDepth));
		}
	}
	return listPoints;
}

void BoxCollider::Move(Vector3 deltaMove)
{
	Collider::Move(deltaMove);
	this->center = this->center + deltaMove;
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
