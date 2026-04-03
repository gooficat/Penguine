#include "Penguine.hxx"
#include "interfaces/Window.hxx"
#include "rendering/Renderer.hxx"
#include <chrono>
#include <cstdint>
#include <ratio>
#include <thread>

namespace Penguine
{

Application::Application(const Interfaces::Window::Spec &window_spec, const double target_fps)
	: window(window_spec), renderer(window_spec.size), input_handler(),
	  target_frame_time(1.0 / static_cast<double>(target_fps))
{
}

void Application::Run()
{
	window.Show();
	frame_start = std::chrono::steady_clock::now();
	while (input_handler.ShouldClose() == false)
	{
		StartFrame();
		input_handler.Update();
		Update(delta_time);
		renderer.Clear();
		Render();
		window.Update();
		EndFrame();
	}
}

void Application::StartFrame()
{
	auto last_frame = frame_start;
	frame_start		= std::chrono::steady_clock::now();
	auto duration	= std::chrono::duration<double>(frame_start - last_frame).count();
	delta_time		= duration;
}

void Application::EndFrame()
{
	if (delta_time < target_frame_time)
	{
		std::this_thread::sleep_for(std::chrono::duration<double>(target_frame_time - delta_time));
	}
}

Application::~Application()
{
}

} // namespace Penguine