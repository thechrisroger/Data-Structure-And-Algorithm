/*!
 * \file ջ��˳��洢ʵ��.cpp
 *
 * \author ranjiewen
 * \date 2017/03/17 11:13
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef int Position;
typedef int ElemType;
#define  ERROR NULL
#define  MAXSIVE 100

struct SNode
{
	ElemType *Data; /*�洢Ԫ�ص����飬��̬�����ڴ�*/
	Position Top; /*ջ��Ԫ�������±�*/
	int MaxSize; // ��ջ�������
};

typedef struct SNode* Stack;

Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElemType*)malloc(MaxSize*sizeof(ElemType));
	S->Top = -1; //˳��洢�ṹʱ����ʾ��
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull(Stack S)
{
	return (S->Top == S->MaxSize - 1);
}

bool Push(Stack S, ElemType x)
{
	if (IsFull(S))
	{
		printf("��ջ��.\n");
		return false;
	}
	else
	{
		S->Data[++(S->Top)] = x;
		return true;
	}
}

bool IsEmpty(Stack S)
{
	return (S->Top == -1);
}

ElemType Pop(Stack S)
{
	if (IsEmpty(S))
	{
		printf("��ջΪ�ա�\n");
		return ERROR;
	}
	else
	{
		return S->Data[(S->Top)--];
	}
}

int main()
{
	struct SNode *S = CreateStack(MAXSIVE);
	for (int i = 9; i >= 0;i--)
	{
		Push(S,i);
	}
	for (int i = 0; i < S->Top;i++)
	{
		printf("%d ", S->Data[i]);
	}
	printf("\n");
	Pop(S);
	Pop(S);
	for (int i = 0; i < S->Top; i++)
	{
		printf("%d ", S->Data[i]);
	}
	printf("\n");
	return 0;
}