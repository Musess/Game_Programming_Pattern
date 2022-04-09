#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

namespace MuSeoun_Engine
{
	class MCConsoleRenderer
	{
	public:
		MCConsoleRenderer() {}
		~MCConsoleRenderer() {}

		void MoveCursor(short x, short y)
		{
			COORD position = { x , y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		}

		void SetCursorState(bool visible)
		{
			CONSOLE_CURSOR_INFO consoleCursorlnfo;
			consoleCursorlnfo.bVisible = visible;
			consoleCursorlnfo.dwSize = 1;
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorlnfo);
		}

		void DrawString(string s)
		{
			cout << s;
		}

		void Clear()
		{

		}
	};
}