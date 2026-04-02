#include "Window.hxx"
#include "InputHandler.hxx"
#include <cstddef>
#include <stdexcept>
#include <wingdi.h>
#include <winuser.h>

namespace Penguine::Interfaces
{

Window *Window::m_instance;

void Window::CreateFakeWindow(const Spec &spec)
{
	// fake window for opengl core profile
}

Window::Window(const Spec &spec)
{
	m_instance = this;
	CreateFakeWindow(spec);

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

	Show();

#endif
}
Window::~Window()
{
	DestroyWindow(m_hwnd);
}

void Window::Show()
{
#ifdef _WIN32
	HDC					  hdc = GetDC(m_hwnd);
	PIXELFORMATDESCRIPTOR pfd = {
		.nSize		  = sizeof(PIXELFORMATDESCRIPTOR),
		.nVersion	  = 1,
		.dwFlags	  = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		.iPixelType	  = PFD_TYPE_RGBA,
		.cColorBits	  = 32,
		.cDepthBits	  = 24,
		.cStencilBits = 8,
		.iLayerType	  = PFD_MAIN_PLANE,
	};
	int pixelFormat = ChoosePixelFormat(hdc, &pfd);
	SetPixelFormat(hdc, pixelFormat, &pfd);
	HGLRC hglrc = wglCreateContext(hdc);
	wglMakeCurrent(hdc, hglrc);
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
	SwapBuffers(GetDC(m_hwnd));
#endif
}

} // namespace Penguine::Interfaces