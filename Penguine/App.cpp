#include "App.h"

using namespace Penguine;

App::App(uint16_t width, uint16_t height, const std::string& name)
{
	Penguine::App::app_instance = this;

	this->Logger = new Penguine::Logger();

	this->Logger->Log(LogType::Info, "Application launched.");

	this->Window = new Penguine::Window(name);

	this->Logger->Log(LogType::Info, "Window created.");
}

App::compl App()
{
	free(this->Logger);
	free(this->Window);
}

void App::Run()
{
	while (true);
}