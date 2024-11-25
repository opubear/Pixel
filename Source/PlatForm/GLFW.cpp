
#include <stdexcept>
#include "PlatForm/GLFW.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
	auto app = reinterpret_cast<GLFW*>(glfwGetWindowUserPointer(window));
	app->framebufferResized = true;
}

void GLFW::CreateSurface(VkInstance instance, VkSurfaceKHR& outSurface) {
	VkResult reuslt = glfwCreateWindowSurface(instance, Window, nullptr, &outSurface);
	if (reuslt != VK_SUCCESS) {
		throw std::runtime_error("failed to create window surface!");
	}
}

GLFW* GLFW::Get()
{
	static GLFW* Glfw = nullptr;
	if (!Glfw) 
	{
		Glfw = new GLFW();
	}

	return Glfw;
}

void GLFW::InitWindow()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	Window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	glfwSetWindowUserPointer(Window, this);
	glfwSetFramebufferSizeCallback(Window, framebufferResizeCallback);
}

GLFWwindow* GLFW::GetWindows()
{
	return Window;
}

void GLFW::Clean()
{
	glfwDestroyWindow(Window);
	glfwTerminate();
}

GLFW::~GLFW()
{
	GLFW* glfw = Get();
	if (glfw)
	{
		delete glfw;
	}
}