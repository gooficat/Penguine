#include "InputHandler.hxx"
#include <Windows.h>

namespace Penguine
{
namespace Interfaces
{

InputHandler *InputHandler::m_instance;

LRESULT CALLBACK InputHandler::Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN:
		m_instance->Keys[wParam] = true;
		return 0;
	case WM_KEYUP:
		m_instance->Keys[wParam] = false;
		return 0;
	default:
		return DefWindowProcA(hWnd, uMsg, wParam, lParam);
	}
}

InputHandler::InputHandler()
{
	m_instance = this;
}

InputHandler::~InputHandler()
{
}

bool InputHandler::IsKeyDown(int keycode) const
{
	return false;
}

bool InputHandler::IsMouseButtonDown(int button) const
{
	return false;
}

bool InputHandler::ShouldClose() const
{
	return false;
}

void InputHandler::Update()
{
	MSG msg;
	if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
}

const Mathematics::Vec<double, 2> &InputHandler::GetMousePosition() const
{
	return MousePos;
}

} // namespace Interfaces
} // namespace Penguine