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
