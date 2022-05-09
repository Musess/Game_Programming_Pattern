#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool isGameRunning;
		MCConsoleRenderer cRrenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		Player p;

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

			startRenderTimePoint = chrono::system_clock::now();

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
				p.isKeyPrssed();
			}
			else
			{
				p.isKeyUnPressed();
			}
		}
		void Update() 
		{
			
		}
		
		
		void Render() 
		{
			cRrenderer.Clear();


			cRrenderer.MoveCursor(p.x, p.y);
			cRrenderer.DrawString("P");
			

			
			cRrenderer.MoveCursor(10, 20);


			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();


			string fps = "FPS(millseconds) : " + to_string(1.0 / renderDuration.count());
			cRrenderer.DrawString(fps);

			
			
		
		
			
			this_thread::sleep_for(chrono::milliseconds(20));

		
	

			
		

			

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
