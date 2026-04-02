#include "Penguine.hxx"
#include "interfaces/Window.hxx"
#include "rendering/Renderer.hxx"

namespace Penguine
{

Application::Application(const Interfaces::Window::Spec &window_spec) : window(window_spec), renderer(), input_handler()
{
	window.Show();
}

void Application::Run()
{
	while (input_handler.ShouldClose() == false)
	{
		window.Update();
		renderer.Render();
		input_handler.Update();
	}
}

Application::~Application()
{
}

} // namespace Penguine