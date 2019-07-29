/*!
 * \file 02-���Խṹ2 һԪ����ʽ�ĳ˷���ӷ�����.cpp
 *
 * \author ranjiewen
 * \date 2017/03/19 16:11
 *
 * 
 */
   

//��̬����ʵ�ֽϺ�

//���������

#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode* Polynomial;

struct PolyNode{
	int coef;
	int expon;
	Polynomial next;
};

Polynomial ReadPoly();
Polynomial Mult(Polynomial P1,Polynomial P2);
void PrintPoly(Polynomial PP);
Polynomial Add(Polynomial P1,Polynomial P2);

int main() //�����ܴ
{
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();

	PP = Mult(P1, P2);
	PrintPoly(PP);

	PS = Add(P1, P2);
	PrintPoly(PS);

	return 0;
}

//��Rearָ��Ĵ���1.��ֵΪNULL,�����Ƿ�Ϊ������ͬ����2.ָ��һ���սڵ�
//*pRear��ǰ������ʽβ��ָ���ָ��
//����ʵ����pRear�������ڵ�
void Attach(int c, int e, Polynomial *pRear)  
{
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->next = NULL;
	(*pRear)->next = P;
	*pRear = P;
}

Polynomial ReadPoly()
{
	Polynomial P, Rear, t;
	int c, e, N;
	scanf("%d", &N);
	P = (Polynomial)malloc(sizeof(struct PolyNode)); //����ͷ�սڵ�
	P->next = NULL;
	Rear = P; 
	while (N--)
	{
		scanf("%d %d", &c, &e);
		if (c != 0)  
		   Attach(c, e, &Rear); //����ǰ��������ʽβ��
	}
	t = P;
	P = P->next;
	free(t); //ɾ����ʱ���ɵ�ͷ���
	return P;
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial t1, t2;
	t1 = P1;
	t2 = P2;
	//�����µ�ͷ���
	Polynomial P,t;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->next = NULL;
	Polynomial Rear;
	Rear = P;
	while (t1&&t2)
	{
		if (t1->expon==t2->expon)
		{
			if (t1->coef+t2->coef)  //ϵ����Ϊ0ʱ����ӵ�β�ڵ���  /*������ȫ*/
			{
				Attach(t1->coef + t2->coef, t1->expon, &Rear);
			}
			t1 = t1->next;
			t2 = t2->next;
		}
		else if (t1->expon>t2->expon)
		{
			Attach(t1->coef, t1->expon, &Rear);
			t1=t1->next;
		}else 
		{
			Attach(t2->coef, t2->expon, &Rear);
			t2 = t2->next;
		}
	}
	while (t1)
	{
		Attach(t1->coef, t1->expon, &Rear);
		t1 = t1->next;
	}
	while (t2)
	{
		Attach(t2->coef, t2->expon, &Rear);
		t2 = t2->next;
	}
	t = P;
	P = P->next;
	free(t);
	return P;
}

//����ʽ�˷�������
//1. ���˷�����ת��Ϊ�ӷ����㣬��P1��ÿһ���P2��ˣ��ڼӵ��������ʽ��
//2. ������룬��P1��ǰ���P2��ǰ��ڲ��뵽������ʽ�У��ؼ���Ҫ�ҵ������λ��

Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear;
	Polynomial t1, t2, t;
	if (!P1||!P2)
	{
		return NULL;
	}
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	Rear = P;
	while (t2)
	{
		//����P1�ĵ�һ�����P2,�õ���ʼ�������ʽ
		Attach(t1->coef*t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->next;
	}
	t1 = t1->next;
	while (t1)
	{
		t2 = P2;
		Rear = P; //��β�ڵ��õ�ͷ�����
		while (t2)
		{
			int e = t1->expon + t2->expon;
			int c = t1->coef * t2->coef;   //�Ժ��ÿһ����˵Ľ��
			while (Rear->next&&Rear->next->expon>e) //�Ҳ���λ��
			{
				Rear = Rear->next;
			}
			if (Rear->next&&Rear->next->expon==e)
			{
				if (Rear->next->coef+c) //��ϵ���Ƿ�Ϊ0
				{
					Rear->next->coef += c;
				}
				else  //Ϊ0ɾ���ڵ�
				{
					t = Rear->next;
					Rear->next = t->next;
					free(t);
				}
			}
			else  //����λ��
			{
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->next = Rear->next;
				Rear->next = t;

				Rear = Rear->next;
			}
			t2 = t2->next;
		}
		t1 = t1->next;
	}
	t2 = P;
	P = P->next;
	free(t2);

	return P;
}

void PrintPoly(Polynomial P)
{
	int flag = 0;//�������������ʽ
	if (!P)
	{
		printf("0 0\n"); /*��ʽ*/
		return;
	}
	while (P)
	{
		if (!flag) //��һ��
		{
			flag = 1;
		}
		else
		{
			printf(" ");
		}
		printf("%d %d", P->coef, P->expon);
		P = P->next;
	}
	printf("\n");
}

