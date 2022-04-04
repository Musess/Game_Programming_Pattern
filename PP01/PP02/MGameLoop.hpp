#pragma once

namespace Musoeun
{
	void Start()
	{
		std::cout << "�ʱ�ȭ ��..\n";
	}

	void Input()
	{
		int a;
		std::cout << "�Է� ��..\n";
		std::cin >> a;
	}

	void Update()
	{
		std::cout << "Update ��..\n";
	}

	void Render()
	{
		std :: cout << "Rendering��..\n";
	}
	
	void Release()
	{
		std::cout << "���� ��..\n";
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