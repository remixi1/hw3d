#include "App.h"

#include "Box.h"
#include "Cylinder.h"
#include "Pyramid.h"
#include "SkinnedBox.h"
#include "AssTest.h"
#include <memory>
#include <algorithm>
#include "HwMath.h"
#include "Surface.h"
#include "GDIPlusManager.h"
#include "imgui/imgui.h"



namespace dx = DirectX;

GDIPlusManager gdipm;



App::App()
	:
	wnd(800, 600, " The Donkey fart box "),
	light(wnd.Gfx())
{
	

	wnd.Gfx().SetProjection(dx::XMMatrixPerspectiveLH(1.0f, 3.0 / 4.0f, 0.5f, 40.0f));

}
void App::DoFrame()
{

	const auto dt = timer.Mark() * speed_factor;
	wnd.Gfx().BeginFrame(0.07f, 0.0f, 0.12f);
	wnd.Gfx().SetCamera(cam.GetMatrix());
	light.Bind(wnd.Gfx(), cam.GetMatrix());

	nano.Draw(wnd.Gfx());
	light.Draw(wnd.Gfx());


	// imgui windows
	
	cam.SpawnControlWindow();
	light.SpawnControlWindow();
	

	// present
	wnd.Gfx().EndFrame();
}



App::~App()
{}




int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
		DoFrame();
	}
}