#include "Border.h"



void Border::Collision(Shape * s)
{
	if (s->getTag().compare(DEFINE::TAG_OBJ) == 0)
	{
		BorderCollider *border = dynamic_cast<BorderCollider*>(this->collider);
		DEFINE::EDirection dir = border->DirectionCollision(*(s->getCollider()));
		if ((dir == DEFINE::EDirection::LEFT && s->getVelocity().getX() < 0) || (dir == DEFINE::EDirection::RIGHT && s->getVelocity().getX() > 0))
		{
			s->setVelocity(Vector3(-s->getVelocity().getX(), s->getVelocity().getY(), s->getVelocity().getZ()));
		}
		else if ((dir == DEFINE::EDirection::TOP && s->getVelocity().getY() > 0) || (dir == DEFINE::EDirection::BOTTOM && s->getVelocity().getY() < 0))
		{
			s->setVelocity(Vector3(s->getVelocity().getX(), -s->getVelocity().getY(), s->getVelocity().getZ()));

		}
		else if ((dir == DEFINE::EDirection::BACK && s->getVelocity().getZ() < 0) || (dir == DEFINE::EDirection::FRONT && s->getVelocity().getZ() > 0))
		{
			s->setVelocity(Vector3(s->getVelocity().getX(), s->getVelocity().getY(), -s->getVelocity().getZ()));
		}
	}
}

Border::Border() : Box()
{
	center = Vector3(0, 0, 0);
	width = 1;
	height = 1;
	depth = 1;
	tag = DEFINE::TAG_BORDER;
	collider = new BorderCollider();
}

Border::Border(Vector3 cen, int w, int h, int d)
{
	center = cen;
	width = w;
	height = h;
	depth = d;
	tag = DEFINE::TAG_BORDER;
	collider = new BorderCollider(cen, w, h ,d);
}


Border::~Border()
{
}
