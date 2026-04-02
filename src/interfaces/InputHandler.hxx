#pragma once

#include "mathematics/Vec.hxx"
#include <Windows.h>
namespace Penguine
{
namespace Interfaces
{

class InputHandler
{
  public:
	enum class EventType
	{
		None,
		KeyDown, // mouse buttons are considered keys
		KeyUp,
		MouseMove,
		MouseWheel,
		WindowResize,
		WindowClose,
		WindowFocus,
		WindowUnfocus,
	};

	enum class KeyCode
	{
		Space	  = 0x20,
		Enter	  = 0x0D,
		BackSpace = 0x08,
		N0		  = 0x30,
		N1,
		N2,
		N3,
		N4,
		N5,
		N6,
		N7,
		N8,
		N9,
		A = 0x41,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
	};

	InputHandler();
	~InputHandler();

	void Update();

	bool IsKeyDown(int keycode) const;
	bool IsMouseButtonDown(int button) const;
	bool ShouldClose() const;

	const Mathematics::Vec<double, 2> &GetMousePosition() const;

	static LRESULT CALLBACK Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	static InputHandler *m_instance;

  private:
	friend class Window;

	bool						m_Keys[256];
	Mathematics::Vec<double, 2> m_MousePos;
	bool						m_ShouldClose;

	void ReceiveEvent();
};

} // namespace Interfaces
} // namespace Penguine