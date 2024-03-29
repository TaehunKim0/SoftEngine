#pragma once

struct ScreenPoint {
	ScreenPoint(const int& InX, const int& InY)
	{
		X = InX; Y = InY;
	}
	int X = 0; int Y = 0; 
};

namespace WindowsApp
{
	static HINSTANCE g_Instance;
	static HWND g_Handle;
	
	static const TCHAR* g_ClassName = _T("SOFTWARE RENDERER");
	static ScreenPoint g_ScreenSize(0,0);
	static TCHAR g_Title[64] = _T("SOFT RENDERER");

#pragma region WndProc
	LRESULT CALLBACK WndProc(HWND hwnd, UINT32 msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_DISPLAYCHANGE:
		case WM_SIZE:
		{


			break;
		}
		case WM_CLOSE:
		{
			::DestroyWindow(hwnd);
			return 0;
		}
		case WM_DESTROY:
		{
			::PostQuitMessage(0);
			break;
		}
		}

		return ::DefWindowProc(hwnd, msg, wParam, lParam);
	}
#pragma endregion

#pragma region CreateWindow
	bool Create(HINSTANCE InhInstance, const ScreenPoint& InScreenSize)
	{
		g_Instance = InhInstance;

		WNDCLASSEX wcex;
		::memset(&wcex, 0, sizeof(wcex));
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wcex.lpfnWndProc = WndProc;
		wcex.hInstance = g_Instance;
		wcex.hIcon = LoadIcon(g_Instance, MAKEINTRESOURCE(IDI_SWORD));
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = g_ClassName;

		if (!::RegisterClassEx(&wcex))
		{
			::MessageBox(nullptr, "Window registration failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
			return false;
		}

		RECT rect;
		rect.left = 0;
		rect.top = 0;
		rect.right = InScreenSize.X - 1;
		rect.bottom = InScreenSize.Y - 1;
		::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		int WindowWidth = rect.right - rect.left + 1;
		int WindowHeight = rect.bottom - rect.top + 1;

		g_Handle = ::CreateWindow(g_ClassName, g_Title, WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,
			(::GetSystemMetrics(SM_CXFULLSCREEN) - WindowWidth) / 2, (::GetSystemMetrics(SM_CYFULLSCREEN) - WindowHeight) / 2, WindowWidth, WindowHeight,
			NULL, NULL, g_Instance, NULL);

		if (!g_Handle)
		{
			::MessageBox(nullptr, "Window creation failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
			return false;
		}

		return true;

	}

#pragma endregion

#pragma region Tick
	FORCEINLINE bool Tick()
	{
		MSG msg;
		::ZeroMemory(&msg, sizeof(msg));

		while (::PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				return false;
		}

		return true;
	}

#pragma endregion

	void Destroy()
	{
		::DestroyWindow(g_Handle);
	}
	
	void Show(HWND handle)
	{
		::ShowWindow(handle, SW_SHOW);
		::SetForegroundWindow(handle);
		::SetFocus(handle);
	}

	void GetWindowSize(HWND handle, float* width, float* height)
	{
		RECT rect;
		::GetClientRect(handle, &rect);
		*width = static_cast<float>(rect.right - rect.left);
		*height = static_cast<float>(rect.bottom - rect.top);
	}	
}