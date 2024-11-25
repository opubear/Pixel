#ifndef __ENGINE__
#define __ENGINE__

#include "Render/Render.h"
#include "PlatForm/GLFW.h"

class Engine 
{
public:
	Render* render;
public:
	Engine();
	void Init();
	void Tick();

	void Clear();
	~Engine();
};


#endif // __ENGINE__
