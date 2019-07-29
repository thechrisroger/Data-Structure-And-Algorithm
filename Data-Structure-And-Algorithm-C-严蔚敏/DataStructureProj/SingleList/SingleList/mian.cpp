#include "common.h"
#include "SingleList.h"


Status comp(ElemType c1, ElemType c2)
{
    //����Ԫ���ж����������ΪTrue,����ΪFALSE��
	if (c1 == c2)
	{
		return TRUE;
	}
	else
		return FALSE;
}
void visit(ElemType c)
{
	printf("%d", c);
}

int main()
{
	LinkList L;
	ElemType e, e0;
	Status i;
	int  k;
	SingleList s;
	i = s.InitList(&L);
	for (int j = 1; j <= 5;j++)
	{
		i = s.ListInsert(L, 1, j);
	}
	printf("��L�ı�ͷ���β���1~5��L=");
	s.ListTraverse(L, visit);
	i = s.ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0����)\n", i);
	for (int j = 1; j <= 10;j++)
	{
		s.ListInsert(L,j+5,j);
	}
	printf("��L�ı�β���β���1~10��L=");
	s.ListTraverse(L,visit);
	s.GetElem(L,5,&e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
	for (int j = 0; j <= 1; j++)
	{
		k = s.LocateElem(L, j, comp);
		if (k)
			printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
		else
			printf("û��ֵΪ%d��Ԫ��\n", j);
	}
	for (int j = 1; j <= 2; j++) /* ����ͷ�������� */
	{
		s.GetElem(L, j, &e0); /* �ѵ�j�����ݸ���e0 */
		i = s.PriorElem(L, e0, &e); /* ��e0��ǰ�� */
		if (i == INFEASIBLE)
			printf("Ԫ��%d��ǰ��\n", e0);
		else
			printf("Ԫ��%d��ǰ��Ϊ��%d\n", e0, e);
	}
	for (int j = s.ListLength(L) - 1; j <= s.ListLength(L); j++)/*����������� */
	{
		s.GetElem(L, j, &e0); /* �ѵ�j�����ݸ���e0 */
		i = s.NextElem(L, e0, &e); /* ��e0�ĺ�� */
		if (i == INFEASIBLE)
			printf("Ԫ��%d�޺��\n", e0);
		else
			printf("Ԫ��%d�ĺ��Ϊ��%d\n", e0, e);
	}
	k = s.ListLength(L); /* kΪ�� */
	for (int j = k + 1; j >= k; j--)
	{
		i = s.ListDelete(L, j, &e); /* ɾ����j������ */
		if (i == ERROR)
			printf("ɾ����%d������ʧ��\n", j);
		else
			printf("ɾ����Ԫ��Ϊ��%d\n", e);
	}
	printf("�������L��Ԫ�أ�");
	s.ListTraverse(L, visit);
	s.DestroyList(&L);
	printf("����L��L=%u\n", L);

	return 0;
}