#pragma once

#include "Api.h"

namespace Penguine {
	class PENGUINE_API App
	{
	public:
		App();
		virtual compl App();

		void Run();
	};

	App* CreateApp();
}