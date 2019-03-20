#include "Border.h"



void Border::Collision(Shape * s)
{
	/*if (s->getTag().compare(DEFINE::TAG_OBJ) == 0)
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
	}*/

	collider->Using = false;
}

Border::Border() : Box()
{
	center = Vector3(0, 0, 0);
	width = 1;
	height = 1;
	depth = 1;
	tag = DEFINE::TAG_BORDER;
	collider = new BorderCollider();
	LoadTexture("defaul.bmp");
}

Border::Border(Vector3 cen, int w, int h, int d)
{
	center = cen;
	width = w;
	height = h;
	depth = d;
	tag = DEFINE::TAG_BORDER;
	collider = new BorderCollider(cen, w, h ,d);
	LoadTexture("defaul.bmp");
}


Border::~Border()
{
}

void Border::Draw()
{
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, idTexture);
	Vector3 min(center.getX() - width / 2.0, center.getY() - height / 2.0, center.getZ() - depth / 2.0);
	Vector3 max(center.getX() + width / 2.0, center.getY() + height / 2.0, center.getZ() + depth / 2.0);
	glPushMatrix();
	// left
	glColor3f(color.getX(), color.getY(), color.getZ());
	glBegin(GL_QUAD_STRIP);
	glTexCoord2f(1.0, 0.0); glVertex3f(min.getX(), min.getY(), min.getZ());
	glTexCoord2f(0.0, 0.0); glVertex3f(min.getX(), min.getY(), max.getZ());
	glTexCoord2f(1.0, 1.0); glVertex3f(min.getX(), max.getY(), min.getZ());
	glTexCoord2f(0.0, 1.0); glVertex3f(min.getX(), max.getY(), max.getZ());
	glEnd();

	// right
	glBegin(GL_QUAD_STRIP);
	glTexCoord2f(0.0, 0.0); glVertex3f(max.getX(), min.getY(), min.getZ());
	glTexCoord2f(1.0, 0.0); glVertex3f(max.getX(), min.getY(), max.getZ());
	glTexCoord2f(0.0, 1.0); glVertex3f(max.getX(), max.getY(), min.getZ());
	glTexCoord2f(1.0, 1.0); glVertex3f(max.getX(), max.getY(), max.getZ());
	glEnd();
	// top
	glBegin(GL_QUAD_STRIP);
	glTexCoord2f(0.0, 0.0); glVertex3f(min.getX(), max.getY(), min.getZ());
	glTexCoord2f(0.0, 1.0); glVertex3f(min.getX(), max.getY(), max.getZ());
	glTexCoord2f(1.0, 0.0); glVertex3f(max.getX(), max.getY(), min.getZ());
	glTexCoord2f(1.0, 1.0); glVertex3f(max.getX(), max.getY(), max.getZ());
	glEnd();
	// bot
	glBegin(GL_QUAD_STRIP);
	glTexCoord2f(0.0, 1.0); glVertex3f(min.getX(), min.getY(), min.getZ());
	glTexCoord2f(0.0, 0.0); glVertex3f(min.getX(), min.getY(), max.getZ());
	glTexCoord2f(1.0, 1.0); glVertex3f(max.getX(), min.getY(), min.getZ());
	glTexCoord2f(1.0, 0.0); glVertex3f(max.getX(), min.getY(), max.getZ());
	glEnd();
	// back
	glBegin(GL_QUAD_STRIP);
	glTexCoord2f(0.0, 0.0); glVertex3f(min.getX(), min.getY(), min.getZ());
	glTexCoord2f(0.0, 1.0); glVertex3f(min.getX(), max.getY(), min.getZ());
	glTexCoord2f(1.0, 0.0); glVertex3f(max.getX(), min.getY(), min.getZ());
	glTexCoord2f(1.0, 1.0); glVertex3f(max.getX(), max.getY(), min.getZ());
	glEnd();
	// front
	glBegin(GL_QUAD_STRIP);
	glTexCoord2f(1.0, 0.0); glVertex3f(min.getX(), min.getY(), max.getZ());
	glTexCoord2f(1.0, 1.0); glVertex3f(min.getX(), max.getY(), max.getZ());
	glTexCoord2f(0.0, 0.0); glVertex3f(max.getX(), min.getY(), max.getZ());
	glTexCoord2f(0.0, 1.0); glVertex3f(max.getX(), max.getY(), max.getZ());
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	
	///////////////////////
	/*glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	glPointSize(5.0);
	std::vector<Vector3> list = collider->GetPointsToCheck();
	for (int i = 0; i < list.size(); ++i)
	{
		glVertex3f(list[i].getX(), list[i].getY(), list[i].getZ());
	}
	glEnd();*/
}

void Border::LoadTexture(const char * fileName)
{
	idTexture = ToolKit::initTexture(fileName);
}
