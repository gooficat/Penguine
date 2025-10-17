#pragma once

#include "Api.h"
#include "Log.h"
#include "Scene.h"
#include "Window.h"

namespace Penguine {
	class PENGUINE_API App
	{
	public:
		inline static App *app_instance;

		App(const std::string& name, const uint16_t width, const uint16_t height);
		virtual compl App();

		void Run();


		void RequestDraw(InternalWindow& internal_window, const EventInformation& info);

		void OnWindowResize(InternalWindow& internal_window, const EventInformation& info);
		void RequestTermination(InternalWindow& internal_window, const EventInformation& info);

		Logger* Logger;
	protected:

	private:
		
		Window* Window;
	};


	App* CreateApp();
}