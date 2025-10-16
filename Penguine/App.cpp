#include "App.h"

using namespace Penguine;

App::App()
{
	this->Logger = new Penguine::Logger();

	this->Logger->Log(LogType::Info, "Application launched.");
}

App::compl App()
{

}

void App::Run()
{
	while (true);
}