#include "ToolKit.h"



unsigned char * ToolKit::readBMP(const char * filename, int & w, int & h)
{
	int i;
	FILE* f = fopen(filename, "rb");
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

	// extract image height and width from header
	w = *(int*)&info[18];
	h = *(int*)&info[22];

	int size = 3 * w * h;
	unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
	fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
	fclose(f);

	for (i = 0; i < size; i += 3)
	{
		unsigned char tmp = data[i];
		data[i] = data[i + 2];
		data[i + 2] = tmp;
	}

	return data;
}

ToolKit::ToolKit()
{
}


ToolKit::~ToolKit()
{
}

GLuint ToolKit::initTexture(const char * fileName)
{
	GLuint textureId;
	glGenTextures(1, &textureId);

	glBindTexture(GL_TEXTURE_2D, textureId);

	unsigned char *imgData;
	int imgW, imgH;
	imgData = readBMP(fileName, imgW, imgH);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgW, imgH, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	return textureId;
}
