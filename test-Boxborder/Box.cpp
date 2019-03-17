#include "Box.h"


void Box::Collision(Shape * s)
{
	if (s->getTag().compare(DEFINE::TAG_OBJ) == 0)
	{
		setVelocity(-getVelocity());
	}
	else if (s->getTag().compare(DEFINE::TAG_BORDER) == 0)
	{
		BorderCollider *border = dynamic_cast<BorderCollider*>(s->getCollider());
		DEFINE::EDirection dir = border->DirectionCollision(*(this->collider));
		if (dir == DEFINE::EDirection::LEFT || dir == DEFINE::EDirection::RIGHT)
		{
			velocity.setX(-1 * velocity.getX());
		}
		else if (dir == DEFINE::EDirection::TOP || dir == DEFINE::EDirection::BOTTOM)
		{
			velocity.setY(-1 * velocity.getY());

		}
		else if (dir == DEFINE::EDirection::BACK || dir == DEFINE::EDirection::FRONT)
		{

			velocity.setZ(-1 * velocity.getZ());
		}
	}
}

void Box::Move(float deltaTime)
{
	this->center = this->center + velocity * deltaTime;
	collider->Move(velocity * deltaTime);
}

void Box::Draw()
{
	Vector3 min(center.getX() - width / 2.0, center.getY() - height / 2.0, center.getZ() - depth / 2.0);
	Vector3 max(center.getX() + width / 2.0, center.getY() + height / 2.0, center.getZ() + depth / 2.0);
	glPushMatrix();
	// left
	glColor3f(color.getX(), color.getY(), color.getZ());
	glBegin(GL_QUAD_STRIP);
	glVertex3f(min.getX(), min.getY(), min.getZ());
	glVertex3f(min.getX(), min.getY(), max.getZ());
	glVertex3f(min.getX(), max.getY(), min.getZ());
	glVertex3f(min.getX(), max.getY(), max.getZ());
	glEnd();

	// right
	glBegin(GL_QUAD_STRIP);
	glVertex3f(max.getX(), min.getY(), min.getZ());
	glVertex3f(max.getX(), min.getY(), max.getZ());
	glVertex3f(max.getX(), max.getY(), min.getZ());
	glVertex3f(max.getX(), max.getY(), max.getZ());
	glEnd();
	// top
	glBegin(GL_QUAD_STRIP);
	glVertex3f(min.getX(), max.getY(), min.getZ());
	glVertex3f(min.getX(), max.getY(), max.getZ());
	glVertex3f(max.getX(), max.getY(), min.getZ());
	glVertex3f(max.getX(), max.getY(), max.getZ());
	glEnd();
	// bot
	glBegin(GL_QUAD_STRIP);
	glVertex3f(min.getX(), min.getY(), min.getZ());
	glVertex3f(min.getX(), min.getY(), max.getZ());
	glVertex3f(max.getX(), min.getY(), min.getZ());
	glVertex3f(max.getX(), min.getY(), max.getZ());
	glEnd();
	// back
	glBegin(GL_QUAD_STRIP);
	glVertex3f(min.getX(), min.getY(), min.getZ());
	glVertex3f(min.getX(), max.getY(), min.getZ());
	glVertex3f(max.getX(), min.getY(), min.getZ());
	glVertex3f(max.getX(), max.getY(), min.getZ());
	glEnd();
	// front
	glBegin(GL_QUAD_STRIP);
	glVertex3f(min.getX(), min.getY(), max.getZ());
	glVertex3f(min.getX(), max.getY(), max.getZ());
	glVertex3f(max.getX(), min.getY(), max.getZ());
	glVertex3f(max.getX(), max.getY(), max.getZ());
	glEnd();
	glPopMatrix();
}

Box::Box()
{
	center = Vector3(0, 0, 0);
	width = 1;
	height = 1;
	depth = 1;
}

Box::Box(Vector3 cen, int w, int h, int d, Vector3 corlor) : Shape(corlor)
{
	center = cen; 
	width = w;
	height = h;
	depth = d;
	collider = new BoxCollider(cen, w, h ,d);
	tag = DEFINE::TAG_OBJ;
}


Box::~Box()
{
}
