
#include "Render.h"
#include "Render\Vulkan\VulkanInstance.h"

Render::Render()
{
	vkInstance = new VulkanInstance();
}

void Render::Init()
{
	vkInstance->Init();
}

void Render::Tick()
{

}

void Render::Clear()
{
	vkInstance->Clear();
}

Render::~Render()
{
	delete vkInstance;
}