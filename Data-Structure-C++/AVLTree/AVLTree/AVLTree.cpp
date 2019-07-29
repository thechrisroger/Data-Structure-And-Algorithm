// AVLTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"AVLTree.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	AVLTree<int> a;
	for (int i = 0; i < 10; i++)
		a.insert(i);
	cout << "���ߣ�" << a.height() << endl;
	cout << "ǰ�����:"  << endl;
	a.preOrder();

	cout << "�������:" << endl;
	a.InOrder();

	cout << "�������:" << endl;
	a.postOrder();
	
	cout << "ɾ��Ԫ��10"<<endl;
	a.remove(10);

	AVLTreeNode<int>* b = a.search_iterator(10);

	if (b != nullptr)
		cout << b->key;
	else
		cout << "�޴�Ԫ��" << endl;

	getchar();

	return 0;
}

