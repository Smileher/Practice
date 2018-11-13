/*
* �ļ�����[���Ա�(˳��洢�ṹ)]
* ���ߣ����ºء�
* �����������Ա�(˳��洢�ṹ)��һЩ��������������ʵ���Լ���ϸע�͡�
* ���ڣ�2018-10-16
*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20  /* �洢�ռ��ʼ������ */
typedef int ElemType;   /* ElemType���͸���ʵ������������������Ϊint */
typedef int Status;     /* Status�Ǻ��������ͣ��䷵��ֵ�Ǻ������״̬���룬��OK  */

typedef struct
{
	ElemType data[MAXSIZE]; /* ����һ��ElemTyoe���͵�����Ϊdata�����飬���鳤��ΪMAXSIZE */
	int length;             /* ����һ��length������Ϊ���Ա�ǰ���� */
}SqList;

/* ��ʼ��˳�����Ա� */
Status InitList(SqList *L)
{
	L->length = 0; /* ���Ա�ĳ���L->length��ֵΪ0 */
	return OK;
}

/* ˳���Ľ��� */
SqList Create(SqList L)
{
	int i;
	srand((unsigned)time(NULL)); /* ��ϵͳ��ǰʱ���ʼ�����Ӵ�������� */
	for (i = 0; i < 10; i++)
	{
		L.data[i] = rand() % 100; /* Ϊ���Ա��е�ÿһ��Ԫ�ظ����ֵ */
		L.length++; /* ÿ��ֵһ�����Ա�ĳ��ȼ�1 */
	}
	return L; /* ����CreateΪSqList���ͣ��������Ա�L */
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ�*/
/* �����������L����Ϊ�ձ� */
Status ClearList(SqList *L)
{
	L->length = 0; /* L->length�ĳ��ȸ�ֵΪ0 */
	return OK;
}


/*��ʼ������ListTraverse�������� */
/*�����������ӡ��ӦԪ�� */
Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		visit(L.data[i]);
	printf("\n");
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L) */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(SqList *L, int i, ElemType e) /* ���Ա�L���������λ��i���������Ԫ��e */
{
	int k;
	if (L->length == MAXSIZE) /* ˳�����Ա����� */
		return ERROR;
	if (i < 1 || i>L->length + 1) /* i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ�� */
		return ERROR;

	if (i <= L->length) /* ����������λ�ò��ڱ�β */
	{
		for (k = L->length - 1; k >= i - 1; k--)  /* k�����Ա������һ��Ԫ�� 1 2 �� 3 4 5 k=5 i=3 */
			L->data[k + 1] = L->data[k]; /* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */
	}
	L->data[i - 1] = e; /* ����Ԫ�ز��� */
	L->length++; /* ���Ա��ȼ�1 */

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(SqList *L, int i, ElemType *e) /* ���Ա�L����ɾ��Ԫ�ص�λ��i�����ڱ���Ԫ�ص�*e */
{
	int k;
	if (L->length == 0) /* ���Ա�Ϊ�� */
		return ERROR;
	if (i < 1 || i>L->length) /* ɾ��λ�ò���ȷ */
		return ERROR;
	*e = L->data[i - 1]; /* �Ѵ�ɾ����Ԫ�ص�ֵ����e */
	if (i < L->length) /* ���ɾ���������λ�� */
	{
		for (k = i; k < L->length; k++) /* ��ɾ��λ�ú��Ԫ��ǰ�� */
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
Status GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i < 1 || i>L.length) /* ������Ա�Ϊ�ձ��λ��iС��1��λ��i����1 */
		return ERROR;
	*e = L.data[i - 1]; /* �ѵ�i��Ԫ�أ���data[]��������i-1��λ�ã���ֵ����e */
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�ĳ��ȡ� */
int ListLength(SqList L)
{
	return L.length;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status ListEmpty(SqList L)
{
	return (L.length == 0) ? TRUE : FALSE;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0) /* ������Ա�Ϊ�ձ� */
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e) /* ���e��ֵ������ĵ�i�������Ա�ĵ�i+1����Ԫ����� */
			break;
	}
	if (i >= L.length) /* ������Ա����Ҳ�����e��ȵ�Ԫ�� */
		return 0;

	return i + 1; /* ����ĵ�i��Ԫ�ص������Ա�ĵ�i+1��Ԫ�� */
}

int main()
{
	SqList L; /* ���Ա� */
	ElemType e; /* Ҫ������Ԫ����ֵ */
	Status i; /* int i */
	int opp; /* ����Ĳ���������� */
	int k; /* int k */
	int pos; /* Ҫ������Ԫ��λ�� */
	ElemType value; /* Ҫ������Ԫ����ֵ */

	i = InitList(&L);
	printf("��ӭʹ�����Ա����(By ChenHe)\n");
	printf("���Ա��ʼ���ɹ���L.length=%d����������²���\n", L.length);
	printf("\n1.���Ա�ֵ \n2.�������Ա� \n3.������Ա� \n4.���Ա���� \n5.���ұ���Ԫ�� \n6.�ж�Ԫ���Ƿ��ڱ��� \n7.ɾ��ĳ��Ԫ�� \n8.���Ա���\n9.���Ա��Ƿ�Ϊ��\n0.�˳� \n��������Ҫ��ɵĲ���(0-9)��\n");
	scanf("%d", &opp);
	while (opp != 1)
	{
		printf("��������1��Ϊ���Ա�ֵ10���������\n");
		scanf("%d", &opp);
	}
	while (opp != 0) {
		switch (opp) {

			//���Ա�ֵ
		case 1:
			L = Create(L);
			printf("�������˳���L.data=");
			ListTraverse(L);
			printf("\n");
			break;

			//�������Ա�
		case 2:
			ListTraverse(L);
			printf("\n");
			break;

			//������Ա�
		case 3:
			i = ClearList(&L);
			printf("���L��L.length=%d\n", L.length);
			ListTraverse(L);
			printf("\n");
			break;

			//���Ա����
		case 4:
			printf("���������Ԫ��λ�ã�");
			scanf("%d", &pos);
			printf("���������Ԫ�ص�ֵ��");
			scanf("%d", &value);
			i = ListInsert(&L, pos, value);
			printf("������ϣ��������Ա�Ϊ��\n");
			ListTraverse(L);
			printf("\n");
			break;

			//���ұ���Ԫ��
		case 5:
			printf("��Ҫ���ҵڼ���Ԫ�أ�");
			scanf("%d", &pos);
			GetElem(L, pos, &e);
			printf("��%d��Ԫ�ص�ֵΪ��%d\n", pos, e);
			break;

			//�ж�Ԫ���Ƿ��ڱ���
		case 6:
			printf("��������֪���Ƿ��ڱ��е���ֵ��");
			scanf("%d", &e);
			k = LocateElem(L, e);
			// ����ٶ���������е�Ԫ�ػ����ظ�
			if (k)
				printf("ֵΪ%d�Ǳ��еĵ�%d��Ԫ��\n", e, k);
			else
				printf("û��ֵΪ%d��Ԫ��\n", e);
			break;

			//ɾ��ĳ��Ԫ��
		case 7:
			printf("Ҫɾ���ڼ���Ԫ�أ�");
			scanf("%d", &pos);
			ListDelete(&L, pos, &e);
			printf("ɾ����ϣ��������Ա�Ϊ��\n");
			ListTraverse(L);
			printf("\n");
			break;

			//���Ա���
		case 8:
			k = ListLength(L);
			printf("���Ա�ĳ���Ϊ: %d \n", k);
			break;

			//���Ա��Ƿ�Ϊ��
		case 9:
			i = ListEmpty(L);
			if (i)
				printf("�����Ա�Ϊ��.\n");
			else
				printf("�����Ա�ǿ�\n");
			break;
			//�˳�
		case 0:
			exit(0);
		default:
			printf("�����������������(0-9)\n");
		}
		printf("������������Ĳ���(0-9):\n");
		scanf("%d", &opp);
	}
}
//By Smileher
