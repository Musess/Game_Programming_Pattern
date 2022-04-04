#pragma once

namespace Musoeun
{
	void Start()
	{
		std::cout << "초기화 중..\n";
	}

	void Input()
	{
		int a;
		std::cout << "입력 중..\n";
		std::cin >> a;
	}

	void Update()
	{
		std::cout << "Update 중..\n";
	}

	void Render()
	{
		std :: cout << "Rendering중..\n";
	}
	
	void Release()
	{
		std::cout << "삭제 중..\n";
	}


	class MGameLoop
	{
	public:
		bool isGameRunning = false;

		MGameLoop(){}
		~MGameLoop(){}

		void Run()
		{
			isGameRunning = true;

			Start();

			while (isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();

		}
	};
}