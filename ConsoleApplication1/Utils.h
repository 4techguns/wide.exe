#include <windows.h>
#include <gdiplus.h>
#include <gdiplusheaders.h>
#include <winuser.h>

class Utils
{
public:
	static HDC desk;
	static int sw;
	static int sh;

	static void HideConsole()
	{
		::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	}

	static void Stretch(int val1, int val2)
	{
		desk = GetDC(0);

		sw = GetSystemMetrics(0);
		sh = GetSystemMetrics(1);
		StretchBlt(desk, val1, 0, sw + val2, sh, desk, 0, 0, sw, sh, SRCCOPY);

		ReleaseDC(0, desk);
	}

	static int ShowWarning()
	{
		return MessageBoxW(NULL, L"this program is harmless, but might annoy you. in case you want to stop this, press win + r, then type \"taskkill /f /im wide.exe\"\r\nare you sure you want to run this?", L"", MB_YESNO | MB_ICONWARNING);
	}
};
