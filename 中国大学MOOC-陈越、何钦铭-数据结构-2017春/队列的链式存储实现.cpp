
/*!
 * \file ���е���ʽ�洢ʵ��.cpp
 *
 * \author ranjiewen
 * \date 2017/03/19 15:18
 *
 * 
 */
#include<stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;

struct Node { /* �����еĽ�� */
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
	Position Front, Rear;  /* ���е�ͷ��βָ�� */
	int MaxSize;           /* ����������� */
};
typedef struct QNode *Queue;

bool IsEmpty(Queue Q)
{
	return (Q->Front->Next == NULL);
}

Queue CreateListQueque()  //��ͷ���Ĳ���
{
	Queue Q;
	Node *p;
	p = (PtrToNode)malloc(sizeof(struct Node)); //�����½ڵ�
	p->Next = NULL;

	Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = p;
	return Q;
}

bool InsertQ(Queue Q, ElementType x)  
{
	Node *p;
	p = (Node*)malloc(sizeof(struct Node));
	if (!p)
	{
		return -1;
	}
	p->Data = x;
	p->Next = NULL;

	Q->Rear->Next = p;
	Q->Rear = p;
	return true;
}

ElementType DeleteQ(Queue Q) //��ͷ������ʽ�����в���
{
	Position FrontCell;
	ElementType FrontElem;

	if (IsEmpty(Q)) {
		printf("���п�");
		return NULL;
	}
	else {
		FrontCell = Q->Front->Next;
		if (Q->Front->Next == Q->Rear) /* ������ֻ��һ��Ԫ�� */
			Q->Front = Q->Rear = NULL; /* ɾ���������Ϊ�� */
		else
			Q->Front->Next = Q->Front->Next->Next;
		FrontElem = FrontCell->Data;

		free(FrontCell);  /* �ͷű�ɾ�����ռ�  */
		return  FrontElem;
	}
}

void Destroy_Queque(Queue Q)
{
	while (Q->Front!=NULL)
	{
		Q->Rear = Q->Front->Next;
		free(Q->Front);
		Q->Front = Q->Rear;
	}
}

int main()
{
	Queue Q;
	Q = CreateListQueque();

	for (int i = 9; i > 0;i--)
	{
		InsertQ(Q, i);
	}

	Position temp = Q->Front->Next;
	while (temp != Q->Rear->Next)
	{
		printf("%d ", temp->Data);
		temp = temp->Next;
	}
	printf("\n");
	DeleteQ(Q);
	DeleteQ(Q);

	while (Q->Front->Next != Q->Rear->Next)
	{
		printf("%d ", Q->Front->Next->Data);
		Q->Front->Next = Q->Front->Next->Next;
	}
	printf("\n");
	return 0;
}