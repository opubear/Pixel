#ifndef __VULKAN_INSTANCE__
#define __VULKAN_INSTANCE__

#include <vector>
#include "PlatForm/GLFW.h"

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};


class VulkanInstance {
public:
	VkInstance Instance{VK_NULL_HANDLE};
	GLFWwindow* Window{ nullptr };
	VkSurfaceKHR Surface{ VK_NULL_HANDLE };
	VkDebugUtilsMessengerEXT DebugMessenger{ VK_NULL_HANDLE };
	class VulkanDevice* Device{ nullptr };

protected:
	void SetupDebugMessenger();
	void CreateInstance();
public:
	void Init();
	void Clear();
	VkSurfaceKHR& GetSurface();
};

#endif // __VULKAN_INSTANCE__
