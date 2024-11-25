#ifndef __GLFW__
#define __GLFW__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class GLFW {
	GLFWwindow* Window;

public:
	bool framebufferResized = false;

public:
	static GLFW* Get();

	void InitWindow();

	GLFWwindow* GetWindows();

	void CreateSurface(VkInstance instance, VkSurfaceKHR& outSurface);

	void Clean();

	~GLFW();
};


#endif // __GLFW__
