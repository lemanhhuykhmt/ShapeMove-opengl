#pragma once
#include "Box.h"
#include "ToolKit.h"
class Border : public Box
{
private:
	GLint idTexture;
public:
	void Collision(Shape* s);
	Border();
	Border(Vector3 cen, int w, int h, int d);
	~Border();

	void Draw();
	void LoadTexture(const char *fileName);
};

