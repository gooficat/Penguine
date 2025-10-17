#include "App.h"

using namespace Penguine;

App::App(const std::string& name, const uint16_t width, const uint16_t height)
{
	Penguine::App::app_instance = this;

	this->Logger = new Penguine::Logger();

	this->Logger->Log(LogType::Info, "Application launched.");

	this->Window = new Penguine::Window(name, width, height);

	if (this->Window == nullptr) {
		Logger->Log(LogType::Error, "Window failed to launch!");
	}
	else {
		this->Logger->Log(LogType::Info, "Window created.");
	}
}

App::compl App()
{
	free(this->Logger);
	free(this->Window);
}

void App::Run()
{
	this->Window->Show();
	Logger->Log(LogType::Info, "Running.", true);
	while (true);
}

void App::RequestDraw(InternalWindow& internal_window, const EventInformation& info) {
	Penguine::Window::DefaultWindowProcedure(internal_window, EventType::WindowClose, info);
}

void App::OnWindowResize(InternalWindow& internal_window, const EventInformation& info) {
	Penguine::Window::DefaultWindowProcedure(internal_window, EventType::WindowResize, info);
}
void App::RequestTermination(InternalWindow& internal_window, const EventInformation& info) {
	Penguine::Window::DefaultWindowProcedure(internal_window, EventType::Terminate, info);
}