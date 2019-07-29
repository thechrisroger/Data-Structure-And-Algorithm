
/*!
 * \file ���Խṹջ����ʽ�洢ʵ��.cpp
 *
 * \author ranjiewen
 * \date 2017/03/17 14:27
 *
 * 
 */

#include<stdio.h>
#include <stdlib.h>
typedef int ElementType;
#define  ERROR NULL

typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{ /* ����һ����ջ��ͷ��㣬���ظý��ָ�� */
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool IsEmpty(Stack S)
{ /* �ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false */
	return (S->Next == NULL);
}

bool Push(Stack S, ElementType X)
{ /* ��Ԫ��Xѹ���ջS */
	PtrToSNode TmpCell;

	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	if (!TmpCell)
	{
		printf("������ʧ��!");
		exit(-1);
	}
	TmpCell->Data = X;        //�൱���ڱ�ͷ����
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
}

ElementType Pop(Stack S)
{ /* ɾ�������ض�ջS��ջ��Ԫ�� */
	PtrToSNode FirstCell;
	ElementType TopElem;

	if (IsEmpty(S)) {
		printf("��ջ��");
		return ERROR;
	}
	else {
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
}

int main()
{
	PtrToSNode stack;
	stack = CreateStack();
	for (int i = 9; i >= 0;i--)
	{
		Push(stack, i);
	}
	PtrToSNode pTemp;
	for (pTemp = stack->Next; pTemp != NULL;pTemp=pTemp->Next) //��ʽ������++
	{
		printf("%d ", pTemp->Data);
	}
	printf("\n");
	Pop(stack);
	Pop(stack);
	for (pTemp = stack->Next; pTemp != NULL; pTemp=pTemp->Next)
	{
		printf("%d ", pTemp->Data);
	}
	printf("\n");
}