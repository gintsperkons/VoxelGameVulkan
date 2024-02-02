
//Libraries
#define GLFW_INCLUDE_VULKAN

//Inbuilt
#include <stdexcept>
#include <vector>
#include <iostream>

//SourceCode
#include "../GameEngine/Engine.h"



int main()
{
	Engine::GetInstance()->Init();
	Window* mainWindow = WindowManager::GetInstance()->GetWindow("main");
	mainWindow->SetTitle("Voxel Game");

	bool Btn1Pressed = false;
	bool Btn2Pressed = false;
	//Main loop until window is closed
	while (!Engine::GetInstance()->ShouldStop())
	{	
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Draw();
		//Not Working Yet
		if(mainWindow->GetKeyState(GLFW_KEY_1) == InputHandling::KeyStates::Pressed 
		|| 	mainWindow->GetKeyState(GLFW_KEY_1) == InputHandling::KeyStates::Held)
		{
			if(!Btn1Pressed)
			{
				std::cout << "Button 1 Pressed" << std::endl;
				mainWindow->ChangeRenderer(1);
				Btn1Pressed = true;
			}
		}
		else
		{
			Btn1Pressed = false;
		}
		if(mainWindow->GetKeyState(GLFW_KEY_2) == InputHandling::KeyStates::Pressed 
		|| 	mainWindow->GetKeyState(GLFW_KEY_2) == InputHandling::KeyStates::Held)
		{
			if(!Btn2Pressed)
			{
				std::cout << "Button 2 Pressed" << std::endl;
				mainWindow->ChangeRenderer(2);
				Btn2Pressed = true;
			}
		}
		else
		{
			Btn2Pressed = false;
		}

	}
	return 0;
}