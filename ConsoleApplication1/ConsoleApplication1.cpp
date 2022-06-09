#include <windows.h>
#include <gdiplus.h>
#include <gdiplusheaders.h>
#include "resource.h"
#include "Utils.h"

using namespace Gdiplus;

int main() {

	Utils::HideConsole();
	if (Utils::ShowWarning() == IDNO) ExitProcess(0);

	PlaySoundW(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);

	while (1) {
		Utils::Stretch(-10, 20);

		Sleep(20);
	}
}