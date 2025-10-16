#pragma once

#include "Api.h"
#include "Log.h"
#include "Scene.h"

namespace Penguine {
	class PENGUINE_API App
	{
	public:
		App();
		virtual compl App();

		void Run();
	private:
		Logger* Logger;
		
	};

	App* CreateApp();
}