#include "Collider.h"

Collider::Collider()
{
}


Collider::~Collider()
{
}

std::vector<Vector3> Collider::GetPointsToCheck()
{
	return listPoints;
}

bool Collider::IsCollsion(Collider &c)
{
	if (Using == false)
	{
		Using = true;
		c.Using = true;
		bool isTrue = c.IsCollsion(*this);
		if (isTrue)
		{
			Using = false;
			return isTrue;
		}
	}
	std::vector<Vector3> points = c.GetPointsToCheck();
	for (auto i = 0; i < points.size(); ++i)
	{
		if (IsPointInSide(points[i]))
		{
			return true;
		}
	}
	Using = false;

	return false;
}

void Collider::Move(Vector3 deltaMove)
{
	for (int i = 0; i < listPoints.size(); ++i)
	{
		listPoints[i] = listPoints[i] + deltaMove;
	}
}

void Collider::Draw()
{
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	glPointSize(5.0);
	std::vector<Vector3> list = GetPointsToCheck();
	for (int i = 0; i < list.size(); ++i)
	{
		glVertex3f(list[i].getX(), list[i].getY(), list[i].getZ());
	}
	glEnd();
}
