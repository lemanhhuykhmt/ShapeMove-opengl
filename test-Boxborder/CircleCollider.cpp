#include "CircleCollider.h"
#define PI 3.1415926
#define ToRad(deg) deg * PI / 180.0


bool CircleCollider::IsPointInSide(Vector3 point)
{
	return (point - center).Magnitude() <= radius;
}

std::vector<Vector3> CircleCollider::GetPointsToCheck()
{
	if (listPoints.size() != 0) return listPoints;
	int numberPoint = 2 * (slices - 1) * (stacks - 1) + 2 * (slices -	1) + 2 * (stacks - 1);
	float deltaTheta = 180 / slices;
	float deltaPhi = 180 / stacks;

	float Theta;
	float Phi;
	for (Phi = 0; Phi <= 180; Phi += deltaPhi)
	{
		for (Theta = 0; Theta < 360; Theta += deltaTheta)
		{
			if ((Phi == 0 || Phi == 180) && (Theta != 0)) continue;
			float x = center.getX() + radius * sin(ToRad(Phi)) * cos(ToRad(Theta));
			float y = center.getY() + radius * sin(ToRad(Phi)) * sin(ToRad(Theta));
			float z = center.getZ() + radius * cos(ToRad(Phi));

			// làm tròn
			x = roundf(x * 100) / 100;
			y = roundf(y * 100) / 100;
			z = roundf(z * 100) / 100;

			listPoints.push_back(Vector3(x, y, z));
		}
	}
	return listPoints;
}

void CircleCollider::Move(Vector3 deltaMove)
{
	Collider::Move(deltaMove);
	this->center = this->center + deltaMove;
}

CircleCollider::CircleCollider()
{
	center = Vector3(0, 0, 0);
	radius = 1.0f;
}

CircleCollider::CircleCollider(Vector3 c, float r)
{
	center = c;
	radius = r;
}


CircleCollider::~CircleCollider()
{
}
