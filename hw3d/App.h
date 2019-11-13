#pragma once
#include "Window.h"
#include "HwTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
#include "Mesh.h"
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

	ImguiManager imgui;
	Window wnd;
	HwTimer timer;
	
	float speed_factor = 1.0f;
	Camera cam;
	PointLight light;
	Model nano{ wnd.Gfx(),"Models\\nano_hierarchy.gltf" };
	
};

