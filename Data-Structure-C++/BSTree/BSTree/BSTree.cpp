// BSTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "BSTree.h"
#include<iostream>
using namespace std;
int main()
{
	BSTree<int> t;
	t.insert(62);
	t.insert(58);
	t.insert(47);
	t.insert(51);
	t.insert(35);
	t.insert(37);
	t.insert(88);
	t.insert(73);
	t.insert(99);
	t.insert(93);
	t.insert(95);

	cout << endl << "���������" << endl;
	t.inOrder();

	cout << "���Ԫ��:" << t.search_maximum() << endl;
	cout << "��СԪ��:" << t.search_minimun() << endl;

	cout << "ɾ��Ԫ��99" << endl;
	t.remove(99);

	cout << "���Ԫ��:" << t.search_maximum() << endl;

	t.destory();

	getchar();
	return 0;
}
