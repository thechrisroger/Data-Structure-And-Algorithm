// Main.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"ArrayStack.h"
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	ArrayStack <int> p(5);
	for (int i = 0; i < 5; i++)
	{
		p.push(i);
	}
	cout << "ջ�Ĵ�С:"<<p.size() << endl;
	cout << "ջ�Ƿ�Ϊ��:"<<p.isEmpty() << endl;
	cout << "ջ��Ԫ�أ�"<<p.top() << endl;
	cout << "���γ�ջ:" << endl;
	while (!p.isEmpty())
	{
		cout << p.pop() << endl;
	}
	getchar();
	return 0;
}

