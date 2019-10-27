#pragma once
#include "Window.h"
#include "HwTimer.h"
#include "ImguiManager.h"

class App
{
public:
	App();
	// Master frame / message loop
	int Go();
	~App();
private:

	void DoFrame();

private:

	ImguiManager imgui;
	Window wnd;
	HwTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	float speed_factor = 1.0f;
	static constexpr size_t nDrawables = 180;
};

