#include "header.h"



int main() {
	LPCWSTR lpParam = L" videoTest.mp4 -noborder -x 1920 -y 1080  -loop 0";
	STARTUPINFO si{ 0 };
	PROCESS_INFORMATION pi{ 0 };

	if (CreateProcess(L"ffplay.exe", (LPWSTR)lpParam, 0, 0, 0, 0, 0, 0, &si, &pi)) {
		Sleep(200);

		HWND hProgram = FindWindow(_T("Progman"), _T("Program Manager"));
		HWND hFfplay = FindWindow(L"SDL_app", 0);
		SetParent(hFfplay, hProgram);


		EnumWindows(EnumWindowProc, (LPARAM)SW_HIDE);

		Sleep(1000);

		EnumWindows(EnumWindowProc, (LPARAM)SW_SHOW);
	}
	else {
		std::cout << GetLastError() << std::endl;
	}
}

BOOL CALLBACK EnumWindowProc(_In_ HWND hwnd, _In_ LPARAM lparam) {
	HWND hDefView = FindWindowEx(hwnd, 0, L"SHELLDLL_DefView", 0);
	if (hDefView != 0) {
		HWND hWorkerw = FindWindowEx(0, hwnd, L"WorkerW", 0);
		ShowWindow(hWorkerw, lparam);

		return FALSE;
	}
	return TRUE;
}