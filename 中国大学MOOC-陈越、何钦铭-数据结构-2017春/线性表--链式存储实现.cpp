
/*!
 * \file ���Ա����ʽ�洢ʵ��.cpp
 *
 * \author ranjiewen
 * \date ���� 2017
 *
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode *PtrToNode;
typedef int ElemType;
struct LNode
{
	ElemType Data;
	PtrToNode Next;
};

typedef PtrToNode Position;
typedef PtrToNode List;

#define  ERROR NULL

int Length(List ptrL)
{
	List p = ptrL;
	int j = 0;
	while (p)
	{
		p = p->Next;
		j++;
	}
	return j;
}

/*����*/
Position Find(List L, ElemType x)  //��ֵ����
{
	Position p = L;/*pָ��L�ĵ�1�����*/
	while (p&&p->Data!=x)
	{
		p = p->Next;
	}
	if (p)
	{
		return p;
	}
	else
	{
		return ERROR;
	}
}

List FindKth(int K, List ptrL)//����Ų���
{
	List p = ptrL;
	int i = 1;
	while (p!=NULL&&i<K)
	{
		p = p->Next;
		i++;
	}
	if (i==K)
	{
		return p;
	}
	else
	{
		return NULL;
	}
}

/*����*/
bool Insert(List L, ElemType x, Position p) //��p��ǰһ�ڵ����
{
	Position temp, pre;
	for (pre = L; pre&&pre->Next != p; pre = pre->Next); //�ҵ�p��ǰһ�����
	if (pre == NULL)
	{
		printf("����λ�ò�������\n");
		return false;
	}
	else
	{
		temp = (Position)malloc(sizeof(struct LNode));
		temp->Data = x;
		temp->Next = p;
		pre->Next = temp;
		return true;
	}
}

List Insert(ElemType x, int i, List ptrL) //�����λ�ò���
{
	List p, s;
	if (i == 1) //�½ڵ�����ڱ�ͷ
	{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = x;
		s->Next = NULL;
		return s;
	}
	p = FindKth(i - 1, ptrL);
	if (p==NULL)
	{
		printf("����i����");
		return NULL;
	}
	else
	{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = x;
		s->Next = p->Next;
		p->Next = s;
		return ptrL;
	}
}

bool Delete(List L, Position p)
{
	Position temp, pre;
	for (pre = L; pre&&pre->Next != p; pre = pre->Next);
	if (pre==NULL||p==NULL)
	{
		printf("ɾ��λ�ò�������\n");
		return false;
	}
	else
	{
		pre->Next = p->Next;
		free(p);
		return true;
	}
}

int main()
{
	List L=NULL;
	for (int i = 1; i < 10;i++)
	{
		L=Insert(9 - i, i, L);
	}
	//Delete(L, );
	printf("�����ȣ�%d", Length(L));
	return 0;
}