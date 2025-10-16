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

		App(uint16_t width, uint16_t height, const std::string& name);
		virtual compl App();

		void Run();

	protected:
		Logger* Logger;

	private:
		
		Window* Window;
	};


	App* CreateApp();
}