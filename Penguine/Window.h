#pragma once

#include "Api.h"
#include "Event.h"
#include "InternalWindow.h"

#include <string>
#include <Windows.h>
#include <functional>

namespace Penguine {
	class Window {
	public:
		inline static Window* window_instance;

		Window(const std::string& name, const uint16_t& width, const uint16_t& height) {
			Penguine::Window::window_instance = this;

			std::wstring title(name.begin(), name.end());
			h_instance = GetModuleHandle(NULL);
			wnd_class = { 0 };
			wnd_class.lpfnWndProc = Window::Procedure;
			wnd_class.hInstance = h_instance;
			wnd_class.lpszClassName = title.c_str();

			RegisterClass(&wnd_class);

			h_window = CreateWindowEx(
				WS_EX_CLIENTEDGE,
				title.c_str(),
				title.c_str(),
				WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, CW_USEDEFAULT,
				width, height,
				NULL,
				NULL,
				h_instance,
				NULL
			);

			if (h_window == NULL) {
				delete this;
			}
		}
		void Show() const {
			ShowWindow(h_window, SW_SHOW);
		}
		compl Window() {
			if (h_window != NULL) {
				DestroyWindow(h_window);
			}
		}

		static LRESULT CALLBACK Procedure(HWND h_wnd, UINT u_msg, WPARAM w_param, LPARAM l_param) {
			EventInformation info(w_param, l_param);
			return EventHandler::ProcessEvent((InternalWindow)h_wnd, (EventType)u_msg, info);
		}

		static LRESULT CALLBACK DefaultWindowProcedure(InternalWindow procedure_window, UINT u_msg, const EventInformation& info) {
			return DefWindowProc(procedure_window, u_msg, info.w_param, info.l_param);
		}
	private:
		WNDCLASS wnd_class;
		HINSTANCE h_instance;
		HWND h_window;
	};
}