#include "Event.h"
#include "Window.h"
#include "App.h"

using namespace Penguine;

LRESULT CALLBACK EventHandler::ProcessEvent(InternalWindow internal_window, EventType type, EventInformation info) {
	switch (type) {
	//case EventType::WindowResize:
	//	Penguine::App::app_instance->OnWindowResize(info);
	//	break;
	//case EventType::WindowClose:
	//case EventType::Terminate:
	//	Penguine::App::app_instance->RequestTermination(info);
	//	break;
	//case EventType::RequestDraw:
	//	Penguine::App::app_instance->RequestDraw(info);
	//	break;
	default:
		return Penguine::Window::DefaultWindowProcedure(internal_window, type, info);
	}
	return 0;
}