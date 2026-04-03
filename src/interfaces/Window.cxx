#include "Window.hxx"
#include "InputHandler.hxx"
#include <libloaderapi.h>
#include <stdexcept>
#include <wingdi.h>
#include <winuser.h>

namespace Penguine::Interfaces
{

Window *Window::m_instance;

Window::Window(const Spec &spec)
{
	m_instance = this;

	WNDCLASS wc = {
		.lpfnWndProc   = InputHandler::Proc,
		.hInstance	   = GetModuleHandle(nullptr),
		.lpszClassName = "PGWND",
	};
	RegisterClass(&wc);

	m_hwnd = CreateWindowEx( //
		0,
		wc.lpszClassName,
		spec.title.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		nullptr,
		nullptr,
		wc.hInstance,
		nullptr //
	);

	if (!m_hwnd)
		throw std::runtime_error("Failed to create window");
}

Window::~Window()
{
	DestroyWindow(m_hwnd);
}

void Window::Show()
{
	ShowWindow(m_hwnd, SW_SHOW);
}

void Window::Update()
{
	MSG msg = {};
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	SwapBuffers(GetDC(m_hwnd));
}

} // namespace Penguine::Interfaces