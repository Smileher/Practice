/*****************
 *�༶��16��ת��
 *�������º�
 *ѧ�ţ�20160566140
 *ʵ��ʮ�Ĳ��������㷨��ʵ��
 *****************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
typedef int InfoType; /* ������������������� */
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))
#define MAXSIZE 10000 /* һ������ʾ����С˳������󳤶� */
#define RANDNUM 10000 /*������ĸ���*/
typedef int KeyType;  /* ����ؼ�������Ϊ���� */
struct timeb t1, t2;
typedef struct
{
    KeyType key;        /* �ؼ����� */
    InfoType otherinfo; /* ������������������������ж��� */
} RedType;              /* ��¼���� */

typedef struct
{
    RedType r[MAXSIZE + 1]; /* r[0]���û������ڱ���Ԫ */
    int length;             /* ˳����� */
} SqList;                   /* ˳������� */

void print(SqList L)
{
    int i;
    for (i = 1; i <= L.length; i++)
        printf("(%d,%d)", L.r[i].key, L.r[i].otherinfo);
    printf("\n");
}
/* bo10-1.c ˳����������ĺ���(3��) */
void InsertSort(SqList *L)
{ /* ��˳���L��ֱ�Ӳ��������㷨10.1 */
    ftime(&t1);
    int i, j, t;
    for (i = 2; i <= (*L).length; ++i)
        if
            LT((*L).r[i].key, (*L).r[i - 1].key) /* "<",�轫L.r[i]���������ӱ� */
            {
                (*L).r[0] = (*L).r[i]; /* ����Ϊ�ڱ� */
                for (j = i - 1; LT((*L).r[0].key, (*L).r[j].key); --j)
                    (*L).r[j + 1] = (*L).r[j]; /* ��¼���� */
                (*L).r[j + 1] = (*L).r[0];     /* ���뵽��ȷλ�� */
            }
    ftime(&t2);
    t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
    printf("ֱ�Ӳ���������ʱ%d����\n", t);
}

void BInsertSort(SqList *L)
{ /* ��˳���L���۰���������㷨10.2 */
    ftime(&t1);
    int i, j, m, low, high, t;
    for (i = 2; i <= (*L).length; ++i)
    {
        (*L).r[0] = (*L).r[i]; /* ��L.r[i]�ݴ浽L.r[0] */
        low = 1;
        high = i - 1;
        while (low <= high)
        {                         /* ��r[low..high]���۰������������λ�� */
            m = (low + high) / 2; /* �۰� */
            if
                LT((*L).r[0].key, (*L).r[m].key)
            high = m - 1;     /* ������ڵͰ��� */
            else low = m + 1; /* ������ڸ߰��� */
        }
        for (j = i - 1; j >= high + 1; --j)
            (*L).r[j + 1] = (*L).r[j]; /* ��¼���� */
        (*L).r[high + 1] = (*L).r[0];  /* ���� */
    }
    ftime(&t2);
    t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
    printf("�۰����������ʱ%d����\n", t);
}

void P2_InsertSort(SqList *L)
{ /* 2_·�������� */
    ftime(&t1);
    int i, j, first, final, t;
    RedType *d;
    d = (RedType *)malloc((*L).length * sizeof(RedType)); /* ����L.length����¼����ʱ�ռ� */
    d[0] = (*L).r[1];                                     /* ��L�ĵ�1����¼Ϊd���ź���ļ�¼(��λ��[0]) */
    first = final = 0;                                    /* first��final�ֱ�ָʾd���ź���ļ�¼�ĵ�1�������1����¼��λ�� */
    for (i = 2; i <= (*L).length; ++i)
    { /* ���ν�L�ĵ�2�������1����¼����d�� */
        if ((*L).r[i].key < d[first].key)
        {                                                    /* �����¼С��d����Сֵ���嵽d[first]֮ǰ(�����ƶ�d�����Ԫ��) */
            first = (first - 1 + (*L).length) % (*L).length; /* ��dΪѭ������ */
            d[first] = (*L).r[i];
        }
        else if ((*L).r[i].key > d[final].key)
        { /* �����¼����d�����ֵ���嵽d[final]֮��(�����ƶ�d�����Ԫ��) */
            final = final + 1;
            d[final] = (*L).r[i];
        }
        else
        {                /* �����¼����d����Сֵ��С��d�����ֵ���嵽d���м�(��Ҫ�ƶ�d�����Ԫ��) */
            j = final++; /* �ƶ�d��β��Ԫ���Ա㰴������¼ */
            while ((*L).r[i].key < d[j].key)
            {
                d[(j + 1) % (*L).length] = d[j];
                j = (j - 1 + (*L).length) % (*L).length;
            }
            d[j + 1] = (*L).r[i];
        }
    }
    for (i = 1; i <= (*L).length; i++)                /* ��d����L.r */
        (*L).r[i] = d[(i + first - 1) % (*L).length]; /* ���Թ�ϵ */
    ftime(&t2);
    t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
    printf("2_·����������ʱ%d����\n", t);
}

RedType randnum(int j)
{
    int i;
    RedType iRandNum[RANDNUM];
    for (i = 0; i < RANDNUM; i++)
    {
        iRandNum[i].key = rand() % RANDNUM;
        iRandNum[i].otherinfo = i;
    }
    return iRandNum[j];
}

#define N 10000
void main()
{
    int i;
    RedType iRandNum[RANDNUM];
    SqList l1, l2, l3;
    for (i = 0; i < N; i++) /* ��l1.r��ֵ */
        l1.r[i + 1] = randnum(i);
    l1.length = N;
    l2 = l3 = l1; /* ����˳���l2��l3��l1��ͬ */
    //printf("����ǰ:\n");
    printf("��10000�����ݽ�������:\n");
    //print(l1);
    InsertSort(&l1);
    //printf("ֱ�Ӳ��������:\n");
    //print(l1);
    BInsertSort(&l2);
    //printf("�۰���������:\n");
    //print(l2);
    P2_InsertSort(&l3);
    //printf("2_·���������:\n");
    //print(l3);
}
