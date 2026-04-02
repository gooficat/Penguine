#pragma once

#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#error Only Windows is supported currently
#endif

#include <cstdint>
#include <minwindef.h>

#include "mathematics/Vec.hxx"

namespace Penguine
{
namespace Interfaces
{
class Window
{
  public:
	class Spec
	{
	  public:
		Mathematics::Vec<std::uint16_t, 2> size;
		bool							   full_screen;
		std::string						   title;
	};

	Window(const Spec &spec);
	~Window();

	void Show();

	void Update();

  private:
#ifdef _WIN32
	HWND m_hwnd;
#endif
	static Window *m_instance;

	friend class InputHandler;
};
} // namespace Interfaces
} // namespace Penguine