#include "Renderer.hxx"

#include "interfaces/Window.hxx"
#include "mathematics/Vec.hxx"
#include "rendering/GL.hxx"
#include <Windows.h>
#include <stdexcept>
#include <wingdi.h>

#pragma comment(lib, "opengl32.lib")

namespace Penguine
{
namespace Rendering
{

Renderer::Renderer(const Math::Vec<std::uint16_t, 2> &size)
{
	LoadGLExts();
	GL::Load();
	GL::ClearColor(0.3f, 0.5f, 0.7f, 1.0f);
	GL::Viewport(0, 0, size[0], size[1]);
}

Renderer::~Renderer()
{
}

void Renderer::Render()
{
	GL::Clear(GL::COLOR_BUFFER_BIT);
}

void Renderer::LoadGLExts()
{
	HDC dc = GetDC(Interfaces::Window::m_instance->m_hwnd);

	PIXELFORMATDESCRIPTOR pfd = {0};
	pfd.nSize				  = sizeof(pfd);
	pfd.nVersion			  = 1;
	pfd.dwFlags				  = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType			  = PFD_TYPE_RGBA;
	pfd.cColorBits			  = 32;
	pfd.cDepthBits			  = 24;
	pfd.cStencilBits		  = 8;
	pfd.iLayerType			  = PFD_MAIN_PLANE;

	int pf = ChoosePixelFormat(dc, &pfd);
	if (!pf)
		throw std::runtime_error("ChoosePixelFormat failed");

	if (!SetPixelFormat(dc, pf, &pfd))
		throw std::runtime_error("SetPixelFormat failed");

	HGLRC dummy = wglCreateContext(dc);
	if (!dummy)
		throw std::runtime_error("wglCreateContext failed");

	wglMakeCurrent(dc, dummy);

	// Load WGL extensions
	auto wglCreateContextAttribsARB =
		(HGLRC(WINAPI *)(HDC, HGLRC, const int *))wglGetProcAddress("wglCreateContextAttribsARB");
	if (!wglCreateContextAttribsARB)
		throw std::runtime_error("wglCreateContextAttribsARB not available");

	// Create core profile context
	int attribs[] = {
		0x2091, // WGL_CONTEXT_MAJOR_VERSION_ARB
		3,
		0x2092, // WGL_CONTEXT_MINOR_VERSION_ARB
		3,
		0x9126,		// WGL_CONTEXT_PROFILE_MASK_ARB
		0x00000001, // WGL_CONTEXT_CORE_PROFILE_BIT_ARB
		0,
	};

	HGLRC context = wglCreateContextAttribsARB(dc, 0, attribs);
	if (!context)
		throw std::runtime_error("wglCreateContextAttribsARB failed");

	wglMakeCurrent(dc, context);
	wglDeleteContext(dummy);
}

} // namespace Rendering
} // namespace Penguine