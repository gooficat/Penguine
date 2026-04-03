#include "Penguine.hxx"
#include "interfaces/Window.hxx"
#include "rendering/Renderer.hxx"

namespace Penguine
{

Application::Application(const Interfaces::Window::Spec &window_spec)
	: window(window_spec), renderer(window_spec.size), input_handler()
{
}

void Application::Run()
{
	window.Show();
	while (input_handler.ShouldClose() == false)
	{
		renderer.Render();
		Update(0.0f);
		window.Update();
		input_handler.Update();
	}
}

Application::~Application()
{
}

} // namespace Penguine