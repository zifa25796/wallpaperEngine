#pragma once

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <tchar.h>

BOOL CALLBACK EnumWindowProc(_In_ HWND hwnd, _In_ LPARAM lparam);