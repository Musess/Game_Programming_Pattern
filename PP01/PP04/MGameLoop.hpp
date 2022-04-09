#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool isGameRunning;
		MCConsoleRenderer cRrenderer;

		

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
			/*chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();
			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;

			cRrenderer.Clear();
			cRrenderer.MoveCursor(10, 20);
			cRrenderer.DrawString("test");
			*/

			int fpscount = 0;
			double millseconds = 0.000;

			while (1)
			{
				fpscount++;
				millseconds = millseconds + 0.001;
				cout << "FPS(millseconds) : "<< fpscount <<"(" << millseconds << ")" << endl;

			}

			
			/*string fps = "FPS(millseconds) : " + to_string();
			cRrenderer.DrawString(fps);*/

		
	

			
		

			

			/*/cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

			int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);

			if (remainingFrameTime > 0)
				this_thread::sleep_for(chrono::microseconds(remainingFrameTime));*/

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
