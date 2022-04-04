#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool isGameRunning;
	public:
		MGameLoop()
		{
			isGameRunning = false;
		}
		~MGameLoop() {}

		void Run()
		{
			isGameRunning = true;

			lnitialize();

			while (isGameRunning)
			{
				Input();
				Update();
				Render();

			}
			Release();
		}
		void Stop()
		{
			isGameRunning = false;
		}

	private :


		void lnitialize() 
		{
			SetCursorState(false);
		}

		void Input() 
		{
			if (GetAsyncKeyState(VK_SPACE) == -0x8000 || GetAsyncKeyState(VK_SPACE) == 0x8001)
			{

			}
			else
			{

			}
		}
		void Update() 
		{
			
		}
		void Render() 
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();
			cout << "Rendering...";
			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;

				cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

			int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);

			if (remainingFrameTime > 0)
				this_thread::sleep_for(chrono::microseconds(remainingFrameTime));

		}

		void Release() {}

	private:

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
	};
}
