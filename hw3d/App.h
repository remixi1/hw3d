#pragma once
#include "Window.h"
#include "HwTimer.h"

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

	Window wnd;
	HwTimer timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};

