#pragma once
#include <GL/glut.h>
#include <iostream>
class ToolKit
{
private:
	static unsigned char* readBMP(const char* filename, int &w, int &h);
	
public:
	ToolKit();
	~ToolKit();
	static GLuint initTexture(const char *fileName);
	
};

