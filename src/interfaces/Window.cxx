#include "Window.hxx"
#include "InputHandler.hxx"
#include <cstddef>
#include <stdexcept>
#include <winuser.h>

namespace Penguine::Interfaces
{

Window *Window::m_instance;

Window::Window(const Spec &spec)
{
	m_instance = this;
#ifdef _WIN32
	HINSTANCE hInstance = GetModuleHandle(NULL);
	WNDCLASSA wndClass	= {
		 .style			= CS_OWNDC,
		 .lpfnWndProc	= InputHandler::Proc,
		 .cbClsExtra	= 0,
		 .cbWndExtra	= 0,
		 .hInstance		= hInstance,
		 .hIcon			= LoadIconA(hInstance, IDI_WINLOGO),
		 .hCursor		= LoadCursorA(NULL, IDC_ARROW),
		 .hbrBackground = NULL,
		 .lpszMenuName	= NULL,
		 .lpszClassName = "Penguine Window",
	 };
	if (!RegisterClassA(&wndClass))
	{
		throw std::runtime_error("Failed to register window class!");
	}

	m_hwnd =
		CreateWindowA("Penguine Window", spec.title.c_str(), WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
					  CW_USEDEFAULT, CW_USEDEFAULT, spec.size[0], spec.size[1], NULL, NULL, hInstance, NULL);

	ShowWindow(m_hwnd, NULL);

#endif
}
Window::~Window()
{
	DestroyWindow(m_hwnd);
}

void Window::Show()
{
#ifdef _WIN32
	ShowWindow(m_hwnd, SW_SHOW);
#endif
}

void Window::Update()
{
#ifdef _WIN32
	MSG msg = {};
	while (PeekMessageA(&msg, m_hwnd, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
#endif
}

} // namespace Penguine::Interfaces