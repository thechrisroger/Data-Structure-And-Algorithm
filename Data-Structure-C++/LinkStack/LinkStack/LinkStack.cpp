/*
*���Դ���
*/
#include "stdafx.h"
#include"LinkStack.h"
#include<iostream>
#include<string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	LinkStack <string> lstack;
	lstack.push("hello");
	lstack.push("to");
	lstack.push("you��");

	cout << "ջ�Ĵ�С:" << lstack.size() << endl;
	cout <<"ջ��Ԫ��:"<< lstack.top() << endl;

	while (!lstack.isEmpty())
	{
		lstack.pop();
	}

	cout << "ջ�Ĵ�С:" << lstack.size() << endl;
	
	getchar();
	return 0;
}

