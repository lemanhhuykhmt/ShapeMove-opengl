#pragma once
#include <string>
#define PI 3.1415956

class DEFINE
{
public:
	DEFINE();
	~DEFINE();	
	const static std::string TAG_OBJ;
	const static std::string TAG_BORDER;
	enum EDirection
	{
		NONE,
		RIGHT,
		LEFT,
		TOP,
		BOTTOM,
		BACK,
		FRONT
	};
};

