#pragma once
#include <string>
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

