#pragma once
#include "Window.h"
#include "HwTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
#include "Mesh.h"
#include "TestPlane.h"
#include "TestCube.h"
#include <set>

class App
{
public:
	App();
	// Master frame / message loop
	int Go();
	~App();
private:

	void DoFrame();
	void ShowImguiDemoWindow();
	
private:
	bool showDemoWindow = false;
	int x = 0, y = 0;
	ImguiManager imgui;
	Window wnd;
	HwTimer timer;
	
	float speed_factor = 1.0f;
	Camera cam;
	PointLight light;
	Model nano{ wnd.Gfx(),"Models\\nano_textured\\nanosuit.obj" };
	Model nano2{ wnd.Gfx(),"Models\\nano_textured\\nanosuit.obj" };
	TestPlane plane;
	TestCube cube;
};

