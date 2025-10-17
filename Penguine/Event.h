#pragma once

#include "Api.h"
#include "Vec.h"

#include "InternalWindow.h"

#include <Windows.h>

namespace Penguine {
	enum class PENGUINE_API KeyCode {
		LMB = 0x01,
		RMB,
		MMB = 0x04,
		N0 = 0x30,
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

	enum EventType : UINT {
		WindowResize = WM_SIZE,
		WindowClose = WM_QUIT,
		Terminate = WM_DESTROY,
		RequestDraw = WM_PAINT
	};

	class EventInformation {
	public:
		WPARAM w_param;
		LPARAM l_param;
	};

	class PENGUINE_API EventHandler {
	public:
		bool IsKeyDown(KeyCode key) {
			// implement as per winapi or whatever platform
			return false;
		}
		Vec2 GetMousePos() {
			// implement as per winapi or whatever platform
			return Vec2();
		}
		static LRESULT CALLBACK ProcessEvent(InternalWindow internal_window, EventType type, EventInformation info);
	private:
	};
};