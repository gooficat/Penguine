#pragma once

#ifdef PENGUINE_DLL
	#define PENGUINE_API __declspec(dllexport)
#else
	#define PENGUINE_API __declspec(dllimport)
#endif