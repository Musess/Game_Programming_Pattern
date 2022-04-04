#include <iostream>
using namespace std;

class A
{
public :
	virtual void dynamic_print()
	{
		cout << "�ƾƾƾƾ�\n";
	}
	void static_print()
	{
		cout << "�ƾ�\n";
	}
};

class B : public A
{
public:
	void dynamic_print()
	{
		cout << "���̳���ũ ����\n";
	}
	void static_print()
	{
		cout << "����\n";
	}

	void static_print(int a)
	{
		cout << a << "�ƾ�\n";
	}
};

void main()
{
	A* tempA;
	A* tempB = new B();
	tempA = tempB;
	tempA->static_print();
	tempB->static_print();

	tempA->dynamic_print();
	tempB->dynamic_print();
}