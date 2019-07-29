
/*!
 * \file ���Ա��˳��洢ʵ��.cpp
 *
 * \author ranjiewen
 * \date ���� 2017
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Position;
typedef struct LNode *List;
#define  MAXSIVE 100

struct LNode
{
	ElemType Data[MAXSIVE];
	Position Last;  //������±�
};

/*��ʼ��*/
List MakeEmpty()
{
	List L; 
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1; //��ʼԪ��λ��Ϊ0
	return L;
}

#define ERROR -1
Position Find(List L, ElemType x)
{
	Position i = 0;
	while (i<=L->Last&&L->Data[i]!=x)
	{
		i++;
	}
	if (i>L->Last)
	{
		return ERROR;  //���û���ҵ������ش�����Ϣ
	}
	else
	{
		return i; //�ҵ��˷��ش洢λ��
	}
}

/*����*/
bool Insert(List L, ElemType X, Position P)
{ /* ��L��ָ��λ��Pǰ����һ����Ԫ��X */
	Position i;

	if (L->Last == MAXSIVE - 1) {
		/* ��ռ����������ܲ��� */
		printf("����");
		return false;
	}
	if (P<0 || P>L->Last + 1) { /* ������λ�õĺϷ��� */
		printf("λ�ò��Ϸ�");
		return false;
	}
	for (i = L->Last; i >= P; i--)
		L->Data[i + 1] = L->Data[i]; /* ��λ��P���Ժ��Ԫ��˳������ƶ� */
	L->Data[P] = X;  /* ��Ԫ�ز��� */
	L->Last++;       /* Last��ָ�����Ԫ�� */
	return true;
}

/* ɾ�� */
bool Delete(List L, Position P)
{ /* ��L��ɾ��ָ��λ��P��Ԫ�� */
	Position i;

	if (P<0 || P>L->Last) { /* ���ձ�ɾ��λ�õĺϷ��� */
		printf("λ��%d������Ԫ��", P);
		return false;
	}
	for (i = P + 1; i <= L->Last; i++)
		L->Data[i - 1] = L->Data[i]; /* ��λ��P+1���Ժ��Ԫ��˳����ǰ�ƶ� */
	L->Last--; /* Last��ָ�����Ԫ�� */
	return true;
}

//������˳��洢�������С

int main()
{
	//List L = MakeEmpty(); //��ȷ�ĳ�ʼ��

	//List L = NULL;//������ĳ�ʼ��

	struct LNode list_; //����ĳ�ʼ��
	list_.Last = -1; //���븳ֵ��
	for (int i = 0; i<4;i++)
	{
		list_.Data[i] = 10 + i;
		list_.Last++;
	}
	List L = &list_; 

	for (int i = 9; i > 0; i--)
	{
		Insert(L, i, 9 - i);
	}

	for (int i = 0; i <= L->Last;i++)
	{
		printf("%d ", L->Data[i]);
	}
	printf("\n");
	return 0;
}