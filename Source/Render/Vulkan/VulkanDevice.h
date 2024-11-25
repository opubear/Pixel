#ifndef __VULKAN_DEVICE__
#define __VULKAN_DEVICE__
#include <volk.h>
#include <optional>
#include <vector>

#include "Render/Vulkan/VulkanInstance.h"

struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete() {
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};

class VulkanDevice {
public:
	VkDevice Device{ VK_NULL_HANDLE };
	VkPhysicalDevice PhysicalDevice{ VK_NULL_HANDLE };

	const VkInstance Instance;
	const VkSurfaceKHR Sruface;

	VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;

	VkQueue GraphicsQueue{ VK_NULL_HANDLE };
	VkQueue PresentQueue{ VK_NULL_HANDLE };

public:
	VulkanDevice(VkInstance instance, VkSurfaceKHR surface) : Instance(instance), Sruface(surface) {}
	void Init();
	void PickPhysicalDevice();
	void CreateLogicalDevice();
	VkFormat FindSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
	SwapChainSupportDetails GetSwapChainSupport();
	QueueFamilyIndices GetQueueFamilies();
	VkSampleCountFlagBits GetMaxUsableSampleCount();
	VkFormatProperties GetFormatProperties(VkFormat imageFormat);
	VkPhysicalDeviceProperties GetDeviceProperties();
	VkPhysicalDeviceMemoryProperties GetMemoryProperties();
	VkQueue GetGraphQueue();
	VkQueue GetPresentQueue();
	VkDevice GetDevice();
	void Clear();
};

#endif // __VULKAN_DEVICE__
