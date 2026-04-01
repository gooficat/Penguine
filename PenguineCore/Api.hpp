#pragma once

#ifdef PENGUINE_BUILD_DLL
	#define PENGUINE_API __declspec(dllexport)
#else
	#define PENGUINE_API __declspec(dllimport)
#endif