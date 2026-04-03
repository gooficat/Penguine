#pragma once

#include "rendering/Renderer.hxx"
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#error Only Windows is supported currently
#endif

#include <cstdint>
#include <minwindef.h>

#include "mathematics/Math.hxx"

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
		Math::Vec<std::uint16_t, 2> size;
		bool						full_screen;
		std::string					title;
	};

	Window(const Spec &spec);
	~Window();

	void Show();

	void Update();

	friend class InputHandler;
	friend class Rendering::Renderer;

  private:
	HWND		   m_hwnd;
	static Window *m_instance;
};
} // namespace Interfaces
} // namespace Penguine