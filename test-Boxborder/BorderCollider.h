#pragma once
#include "BoxCollider.h"
#include "DEFINE.h"
class BorderCollider : public BoxCollider
{
public:
	BorderCollider();
	BorderCollider(Vector3 c, int w, int h, int d);
	~BorderCollider();
	bool IsCollsion(Collider &c);
	DEFINE::EDirection DirectionCollision(Collider &c);
};

