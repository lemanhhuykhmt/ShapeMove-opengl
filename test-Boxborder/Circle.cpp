#include "Circle.h"



void Circle::Collision(Shape * s)
{
	if (this->collider->Using == false)
	{
		this->collider->Using = true;
		s->getCollider()->Using = true;
		s->Collision(this);
	}	
	if (s->getTag().compare(DEFINE::TAG_OBJ) == 0)
	{
		velocity = s->getOldVelocity();
	}
	else if (s->getTag().compare(DEFINE::TAG_BORDER) == 0)
	{
		BorderCollider *border = dynamic_cast<BorderCollider*>(s->getCollider());
		DEFINE::EDirection dir = border->DirectionCollision(*(this->collider));
		if ((dir == DEFINE::EDirection::LEFT && velocity.getX() < 0) || (dir == DEFINE::EDirection::RIGHT && velocity.getX() > 0))
		{
			velocity.setX(-1 * velocity.getX());
		}
		dir = border->DirectionCollision(*(this->collider));
		if ((dir == DEFINE::EDirection::TOP && velocity.getY() > 0) || (dir == DEFINE::EDirection::BOTTOM && velocity.getY() < 0))
		{
			velocity.setY(-1 * velocity.getY());

		}
		dir = border->DirectionCollision(*(this->collider));
		if ((dir == DEFINE::EDirection::BACK && velocity.getZ() < 0) || (dir == DEFINE::EDirection::FRONT && velocity.getZ() > 0))
		{

			velocity.setZ(-1 * velocity.getZ());
		}
	}
	this->collider->Using = false;
}

void Circle::Move(float deltaTime)
{
	this->center = this->center + velocity * deltaTime;
	collider->Move(velocity * deltaTime);
}

void Circle::Draw()
{
	glColor3f(color.getX(), color.getY(), color.getZ());
	glPushMatrix();
//	glLoadIdentity();
	glTranslatef(center.getX(), center.getY(), center.getZ());
	glutSolidSphere(radius, 20, 20);
	glPopMatrix();
}

Circle::Circle()
{
	center = Vector3(0, 0, 0);
	radius = 1;
	collider = new CircleCollider(center, radius);
	tag = DEFINE::TAG_OBJ;
}


Circle::Circle(Vector3 cen, float r, Vector3 corlor) : Shape(corlor)
{
	center = cen;
	radius = r;
	collider = new CircleCollider(cen, radius);
	tag = DEFINE::TAG_OBJ;
}


Circle::~Circle()
{
}
