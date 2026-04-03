#pragma once

#include "interfaces/InputHandler.hxx"
#include "interfaces/Window.hxx"
#include "rendering/Renderer.hxx"
#include <chrono>

namespace Penguine
{
class Application
{
  public:
	Application(const Interfaces::Window::Spec &window_spec, const double target_fps);
	~Application();

	void Run();

	virtual void Update(double deltaTime) = 0;
	virtual void Render()				  = 0;

  protected:
	Interfaces::Window		 window;
	Rendering::Renderer		 renderer;
	Interfaces::InputHandler input_handler;
	double					 target_frame_time;
	double					 delta_time;

  private:
	void StartFrame();
	void EndFrame();

	std::chrono::time_point<std::chrono::steady_clock> frame_start;
};
} // namespace Penguine