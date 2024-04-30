#pragma once
#include <iostream>
#include <windows.h>

void SetColor(int mau_nen, int mau_chu)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int color_code = mau_nen * 16 + mau_chu;
	SetConsoleTextAttribute(hStdout, color_code);
}
