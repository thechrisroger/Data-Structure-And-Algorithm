#include "SingleList.h"


SingleList::SingleList()
{
}


SingleList::~SingleList()
{
}

Status SingleList::InitList(LinkList* L)
{
	/*�������������һ���յ����Ա�L*/
	*L = (LinkList)malloc(sizeof(LNode)); //����ͷ��㣬��ʹLָ���ͷ���
	if (!*L)
	{
		exit(OVERFLOW);
	}
	(*L)->next = nullptr;//ָ�����
	return OK;
}

Status SingleList::DestroyList(LinkList*L)
{
	/*��ʼ���������Ա�L�Ѿ����ڡ�����������������Ա�*/
	LinkList q;
	while (*L)
	{
		q = (*L)->next;
		free(*L);
		*L = q;
	}
	return OK;
}

Status SingleList::ClearList(LinkList L) /*���ı�L*/
{
	/*��ʼ���������Ա�L�Ѿ����ڡ������������L��Ϊ�ձ�*/
	LinkList p, q;
	p = L->next;/*pָ���һ�����*/
	while (p)   
	{
		q = p->next;  //�ȼ�¼��һ��㣬Ȼ���ͷŵ�ǰ���
		free(p);
		p = q;
	}
	L->next = nullptr;  /*ͷ���ָ����Ϊ��*/
	return OK;
}

Status SingleList::ListEmpty(LinkList L)
{
	if (L->next==nullptr)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

Status SingleList::ListLength(LinkList L)
{
	int length=0;
	LinkList q=L->next;
	while (q)
	{
		length++;
		q = q->next;
	}
	return length;
}

Status SingleList::GetElem(LinkList L, int i, ElemType* e)
{
	/* LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ,��ֵ����e������OK,���򷵻�ERROR */
	LinkList q;
	q = L->next;
	int j = 1; /* jΪ������ */
	while (q&&j<i)  /* ˳ָ��������,ֱ��pָ���i��Ԫ�ػ�pΪ�� */
	{
		j++;
		q = q->next;
	}
	if (!q || j>i)  /*��i��Ԫ�ز�����*/
	{
		return ERROR;
	}
	*e = q->data;   /*ȡ��i��Ԫ��*/
	return OK;
}

int SingleList::LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{ /* ��ʼ����: ���Ա�L�Ѵ���,compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0) */
	/* �������: ����L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� */
	/*           ������������Ԫ�ز�����,�򷵻�ֵΪ0 */
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (compare(p->data, e)) /* �ҵ�����������Ԫ�� */
			return i;
		p = p->next;
	}
	return 0;
}

Status SingleList::PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{ /* ��ʼ����: ���Ա�L�Ѵ��� */
	/* �������: ��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��, */
	/*           ����OK;�������ʧ��,pre_e�޶���,����INFEASIBLE */
	LinkList q, p = L->next; /* pָ���һ����� */
	while (p->next) /* p��ָ����к�� */
	{
		q = p->next; /* qΪp�ĺ�� */
		if (q->data == cur_e)
		{
			*pre_e = p->data;
			return OK;
		}
		p = q; /* p����� */
	}
	return INFEASIBLE;
}

Status SingleList::NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{ /* ��ʼ���������Ա�L�Ѵ��� */
	/* �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣� */
	/*           ����OK;�������ʧ�ܣ�next_e�޶��壬����INFEASIBLE */
	LinkList p = L->next; /* pָ���һ����� */
	while (p->next) /* p��ָ����к�� */
	{
		if (p->data == cur_e)
		{
			*next_e = p->next->data;
			return OK;
		}
		p = p->next;
	}
	return INFEASIBLE;
}

Status SingleList::ListInsert(LinkList L, int i, ElemType e) /* �㷨2.9�����ı�L */
{ /* �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e */
	int j = 0;
	LinkList p = L, s;
	while (p&&j<i - 1) /* Ѱ�ҵ�i-1����� */
	{
		p = p->next;
		j++;
	}
	if (!p || j>i - 1) /* iС��1���ߴ��ڱ� */
		return ERROR;
	s = (LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
	s->data = e; /* ����L�� */
	s->next = p->next;
	p->next = s;
	return OK;
}

Status SingleList::ListDelete(LinkList L, int i, ElemType *e) /* �㷨2.10�����ı�L */
{ /* �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ��,����e������ֵ */
	int j = 0;
	LinkList p = L, q;
	while (p->next&&j<i - 1) /* Ѱ�ҵ�i�����,����pָ����ǰ�� */
	{
		p = p->next;
		j++;
	}
	if (!p->next || j>i - 1) /* ɾ��λ�ò����� */
		return ERROR;
	q = p->next; /* ɾ�����ͷŽ�� */
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

Status SingleList::ListTraverse(LinkList L, void(*vi)(ElemType))
/* vi���β�����ΪElemType����bo2-1.c����Ӧ�������β�����ElemType&��ͬ */
{ /* ��ʼ���������Ա�L�Ѵ��� */
	/* �������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� */
	LinkList p = L->next;
	while (p)
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
