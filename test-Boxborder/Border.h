#pragma once
#include "Box.h"
class Border : public Box
{
public:
	void Collision(Shape* s);
	Border();
	Border(Vector3 cen, int w, int h, int d);
	~Border();
};

