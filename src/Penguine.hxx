#pragma once

#include "interfaces/InputHandler.hxx"
#include "interfaces/Window.hxx"
#include "rendering/Renderer.hxx"

namespace Penguine
{
class Application
{
  public:
	Application(const Interfaces::Window::Spec &window_spec);
	~Application();

	void Run();

  protected:
	Interfaces::Window		 window;
	Rendering::Renderer		 renderer;
	Interfaces::InputHandler input_handler;

  private:
};
} // namespace Penguine