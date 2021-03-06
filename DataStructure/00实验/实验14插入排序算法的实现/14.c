/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *实验十四插入排序算法的实现
 *****************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
typedef int InfoType; /* 定义其它数据项的类型 */
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))
#define MAXSIZE 10000 /* 一个用作示例的小顺序表的最大长度 */
#define RANDNUM 10000 /*随机数的个数*/
typedef int KeyType;  /* 定义关键字类型为整型 */
struct timeb t1, t2;
typedef struct
{
    KeyType key;        /* 关键字项 */
    InfoType otherinfo; /* 其它数据项，具体类型在主程中定义 */
} RedType;              /* 记录类型 */

typedef struct
{
    RedType r[MAXSIZE + 1]; /* r[0]闲置或用作哨兵单元 */
    int length;             /* 顺序表长度 */
} SqList;                   /* 顺序表类型 */

void print(SqList L)
{
    int i;
    for (i = 1; i <= L.length; i++)
        printf("(%d,%d)", L.r[i].key, L.r[i].otherinfo);
    printf("\n");
}
/* bo10-1.c 顺序表插入排序的函数(3个) */
void InsertSort(SqList *L)
{ /* 对顺序表L作直接插入排序。算法10.1 */
    ftime(&t1);
    int i, j, t;
    for (i = 2; i <= (*L).length; ++i)
        if
            LT((*L).r[i].key, (*L).r[i - 1].key) /* "<",需将L.r[i]插入有序子表 */
            {
                (*L).r[0] = (*L).r[i]; /* 复制为哨兵 */
                for (j = i - 1; LT((*L).r[0].key, (*L).r[j].key); --j)
                    (*L).r[j + 1] = (*L).r[j]; /* 记录后移 */
                (*L).r[j + 1] = (*L).r[0];     /* 插入到正确位置 */
            }
    ftime(&t2);
    t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
    printf("直接插入排序用时%d毫秒\n", t);
}

void BInsertSort(SqList *L)
{ /* 对顺序表L作折半插入排序。算法10.2 */
    ftime(&t1);
    int i, j, m, low, high, t;
    for (i = 2; i <= (*L).length; ++i)
    {
        (*L).r[0] = (*L).r[i]; /* 将L.r[i]暂存到L.r[0] */
        low = 1;
        high = i - 1;
        while (low <= high)
        {                         /* 在r[low..high]中折半查找有序插入的位置 */
            m = (low + high) / 2; /* 折半 */
            if
                LT((*L).r[0].key, (*L).r[m].key)
            high = m - 1;     /* 插入点在低半区 */
            else low = m + 1; /* 插入点在高半区 */
        }
        for (j = i - 1; j >= high + 1; --j)
            (*L).r[j + 1] = (*L).r[j]; /* 记录后移 */
        (*L).r[high + 1] = (*L).r[0];  /* 插入 */
    }
    ftime(&t2);
    t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
    printf("折半插入排序用时%d毫秒\n", t);
}

void P2_InsertSort(SqList *L)
{ /* 2_路插入排序 */
    ftime(&t1);
    int i, j, first, final, t;
    RedType *d;
    d = (RedType *)malloc((*L).length * sizeof(RedType)); /* 生成L.length个记录的临时空间 */
    d[0] = (*L).r[1];                                     /* 设L的第1个记录为d中排好序的记录(在位置[0]) */
    first = final = 0;                                    /* first、final分别指示d中排好序的记录的第1个和最后1个记录的位置 */
    for (i = 2; i <= (*L).length; ++i)
    { /* 依次将L的第2个～最后1个记录插入d中 */
        if ((*L).r[i].key < d[first].key)
        {                                                    /* 待插记录小于d中最小值，插到d[first]之前(不需移动d数组的元素) */
            first = (first - 1 + (*L).length) % (*L).length; /* 设d为循环向量 */
            d[first] = (*L).r[i];
        }
        else if ((*L).r[i].key > d[final].key)
        { /* 待插记录大于d中最大值，插到d[final]之后(不需移动d数组的元素) */
            final = final + 1;
            d[final] = (*L).r[i];
        }
        else
        {                /* 待插记录大于d中最小值，小于d中最大值，插到d的中间(需要移动d数组的元素) */
            j = final++; /* 移动d的尾部元素以便按序插入记录 */
            while ((*L).r[i].key < d[j].key)
            {
                d[(j + 1) % (*L).length] = d[j];
                j = (j - 1 + (*L).length) % (*L).length;
            }
            d[j + 1] = (*L).r[i];
        }
    }
    for (i = 1; i <= (*L).length; i++)                /* 把d赋给L.r */
        (*L).r[i] = d[(i + first - 1) % (*L).length]; /* 线性关系 */
    ftime(&t2);
    t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
    printf("2_路插入排序用时%d毫秒\n", t);
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
    for (i = 0; i < N; i++) /* 给l1.r赋值 */
        l1.r[i + 1] = randnum(i);
    l1.length = N;
    l2 = l3 = l1; /* 复制顺序表l2、l3与l1相同 */
    //printf("排序前:\n");
    printf("对10000个数据进行排序:\n");
    //print(l1);
    InsertSort(&l1);
    //printf("直接插入排序后:\n");
    //print(l1);
    BInsertSort(&l2);
    //printf("折半插入排序后:\n");
    //print(l2);
    P2_InsertSort(&l3);
    //printf("2_路插入排序后:\n");
    //print(l3);
}
