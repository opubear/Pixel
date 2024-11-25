#ifndef __RENDER__
#define __RENDER__

#include "PlatForm/GLFW.h"
#include "Render/Vulkan/VulkanInstance.h"

class Render {
	VulkanInstance* vkInstance; 
public:
	Render();
	void Init();
	void Tick();
	void Clear();
	VulkanInstance* getInstance() { return vkInstance; }
	~Render();
};

#endif // !__RENDER__
