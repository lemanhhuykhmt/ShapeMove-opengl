#include "Shape.h"



Shape::Shape()
{
}

Shape::Shape(Vector3 col)
{
	color = col;
}


Shape::~Shape()
{
	delete (collider);
}

void Shape::Collision(Shape * s)
{

}

bool Shape::IsCollision(Shape * s)
{

	return this->collider->IsCollsion(*s->collider);
}


