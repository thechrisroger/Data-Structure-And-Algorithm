// Huffman.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Huffman.h"
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	Huffman<int> huff;
	int a[] = { 10,20,30,40 };
	huff.creat(a, 4);	//����һ�ù�������
	huff.print();		//��ӡ�ڵ���ϵ
	getchar();
	return 0;
}

