/*****************************************************
* \file ����ʵ��������ջ.cpp
* \date 2017/03/17 23:02
* \author ranjiewen
* \contact: ranjiewen@outlook.com 
* \����������
��һ������ʵ��������ջ��Ҫ�������������ռ䣬ʹ����ֻҪ�пռ�
��ջ�����Ϳ��Գɹ���
* \���������
����ջ�ֱ���������ͷ��ʼ���м�������������ջ��ջ��ָ������ʱ����ʾ����ջ������

*****************************************************/

#include<stdio.h>
#include <stdlib.h>

#define MAXSIVE 20
typedef int ElementType;
typedef struct DStack *DStack_;
struct DStack
{
	ElementType Data[MAXSIVE];
	int top1;  //ջ1��ջ��ָ��
	int top2;  //ջ2��ջ��ָ��
};

void Push(struct DStack *ptrs, ElementType item, int Tag)
{
	/*Tag��Ϊ����������ջ�ı�־��ȡֵΪ1/2*/
	if (ptrs->top2-ptrs->top1==1)
	{
		printf("ջ����"); return;
	}
	if (Tag==1)
	{
		ptrs->Data[++(ptrs->top1)] = item;
	}
	else
	{
		ptrs->Data[--(ptrs->top2)] = item;
	}
}

ElementType Pop(struct DStack *ptrs,int Tag)
{
	if (Tag==1)
	{
		if (ptrs->top1==-1)
		{
			printf("ջ1�գ�");
			return NULL;
		}
		else
		{
			return ptrs->Data[(ptrs->top1)--];
		}
	}
	else
	{
		if (ptrs->top2==MAXSIVE)
		{
			printf("ջ2�գ�");
			return NULL;
		}
		else
		{
			return ptrs->Data[(ptrs->top2)++];
		}
	}
}

int main()
{
	//struct DStack *S=(DStack_)malloc(sizeof(struct DStack));
	struct DStack stack;
	DStack_ S = &stack;
	S->top1 = -1;
	S->top2 = MAXSIVE;

	for (int i = 0; i < 8;i++)
	{
		Push(S, i, 1);
		Push(S, 8 - i, 2);
	}

	for (int i = 0; i <= S->top1;i++)
	{
		printf("%d ",S->Data[i]);
	}
	printf("\n");
	for (int i = MAXSIVE-1; i >= S->top2; i--)
	{
		printf("%d ", S->Data[i]);
	}
	printf("\n");
	return 0;
}
