#pragma once
#include "common.h"

typedef int ElemType;

//���Ա�ĵ�����洢�ṹ
struct LNode
{
	ElemType data;
	LNode* next;
};
typedef struct LNode* LinkList;


class SingleList
{
public:
	SingleList();
	~SingleList();
public:
	//��������12��
	Status InitList(LinkList*);
	Status DestroyList(LinkList*);
	Status ClearList(LinkList);
	Status ListEmpty(LinkList);
	Status ListLength(LinkList);
	Status GetElem(LinkList, int i, ElemType* e);
	Status LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType));
	Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e);
	Status NextElem(LinkList L, ElemType cur_e,ElemType* next_e);
	Status ListInsert(LinkList L,int i,ElemType e);
	Status ListDelete(LinkList L,int i,ElemType* e);
	Status ListTraverse(LinkList L,void(*vi)(ElemType));
};

