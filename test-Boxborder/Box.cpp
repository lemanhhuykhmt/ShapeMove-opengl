#include "Box.h"


void Box::Collision(Shape * s)
{
	if (this->collider->Using == false)
	{
		this->collider->Using = true;
		s->getCollider()->Using = true;
		s->Collision(this);
	}
	if (s->getTag().compare(DEFINE::TAG_OBJ) == 0)
	{
		/*float alpha = velocity.GetAlpha(s->getOldVelocity());
		if (alpha > PI / 2)
		{
			alpha = PI - alpha;
		}
		Vector3 sum = velocity + s->getOldVelocity();
		Vector3 diff = -velocity + s->getOldVelocity();
		Vector3 newVel = (diff + sum * cos(alpha)) / 2;
		velocity = newVel;
		s->setOldVelocity(s->getVelocity());*/
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
	tag = DEFINE::TAG_OBJ;
}

Box::Box(Vector3 cen, float w, float h, float d, Vector3 corlor) : Shape(corlor)
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
