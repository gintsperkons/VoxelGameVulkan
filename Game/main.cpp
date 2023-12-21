#define GLFW_INCLUDE_VULKAN

#include <stdexcept>
#include <vector>
#include <iostream>

#include "../GameEngine/Engine/Core/Window/WindowManager.h"
#include "../GameEngine/Engine/Core/Rendering/Vulkan/VulkanRenderer.h"

int main()
{
	// Create window
	WindowManager::GetInstance()->InitWindow("Vulkan Voxels", 1080, 720);

	// Create Vulkan Renderer instance
	if (VulkanRenderer::GetInstance()->Init(WindowManager::GetInstance()->GetWindow()) == EXIT_FAILURE)
		return EXIT_FAILURE;

	//Main loop until window is closed
	while (!WindowManager::GetInstance()->WindowShouldClose())
	{
		WindowManager::GetInstance()->PollEvents();
	}
std::cout << "Hello World" << std::endl;
	WindowManager::DestroyInstance();
	VulkanRenderer::DestroyInstance();
	return 0;
}