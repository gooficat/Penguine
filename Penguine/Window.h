#pragma once

#include "Api.h"

#include <string>
#include <Windows.h>
#include <functional>

namespace Penguine {
	class Window {
	public:
		Window(std::string name) {
			std::wstring title(name.begin(), name.end());

			h_instance = GetModuleHandle(NULL);
			wnd_class = { 0 };
			wnd_class.lpfnWndProc = DefWindowProc;
			wnd_class.hInstance = h_instance;
			wnd_class.lpszClassName = title.c_str();

			RegisterClass(&wnd_class);

			h_window = CreateWindowEx(
				0,
				title.c_str(),
				title.c_str(),
				WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
				NULL,
				NULL,
				h_instance,
				NULL
			);

			ShowWindow(h_window, SW_SHOW);
		}
		compl Window() {

		}

		void Process(HWND h_wnd, UINT u_msg, WPARAM w_param, LPARAM l_param) {

		}
	private:
		WNDCLASS wnd_class;
		HINSTANCE h_instance;
		HWND h_window;
	};
}