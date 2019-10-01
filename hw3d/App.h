#pragma once
#include "Window.h"
#include "HwTimer.h"

class App
{
public:
	App();
	// Master frame / message loop
	int Go();

private:

	void DoFrame();

private:

	Window wnd;
	HwTimer timer;

};

