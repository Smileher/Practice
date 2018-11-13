#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE
typedef int ElemType;
typedef int Status;
#define MAXSIZE 1000

typedef struct
{
    ElemType data; //数据
    int cur;       //游标(Cursor)，为0是表示无指向
} Component, StaticLinkList[MAXSIZE];

//初始化
//将一维数组space中各分量链成一备用链表
//space[0].cur为头指针，"0"表示空指针
Status InitList(StaticLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
        space[i].cur = i + 1;

    space[MAXSIZE - 1].cur = 0; //目前静态链表为空，最后一个元素的cur为0
    return OK;
}

//插入操作
//首先是获得空闲分量的下标
//若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur; //当前数组第一个元素的cur存在值
                          //就是要返回的第一个备用空闲的下标
    if (space[0].cur)
        space[0].cur = space[i].cur; //由于要拿出一个分量来使用了
                                     //所以就得把它的下一个分量用来做备用
    return i;
}
//在静态链表L中第i个元素之前插入新的数据元素e
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1; //k首先是数组的最后一个元素的下标
    if (i < 1 || i > ListLength(L) + 1)
        return ERROR;

    j = Malloc_SLL(L); //获得第一个空闲分量的下标赋值给j
    if (j)
    {
        L[j].data = e; //将数据e赋值给此分量的data，下面进行修改游标
        for (l = 1; l < i - 1; l++)
        {
            k = L[k].cur; //找到第i-1个元素的下标赋值给k
        }
        L[j].cur = L[k].cur; //把第i个元素之前的cur赋值给新元素的cur
        L[k].cur = j;        //把新元素的下标赋值给第i-1个元素之前的元素的cur
        return OK;
    }
    return ERROR;
}
//返回L中数据元素个数
int ListLength(StaticLinkList L)
{
    int j = 0;                  //j统计元素个数
    int i = L[MAXSIZE - 1].cur; //i表示游标，初始从第MAXSIZE-1开始
    while (i)                   //判断游标是否为0
    {
        i = L[i].cur;
        j++;
    }
    return j;
}
//静态链表的删除
//删除在L中第i个数据元素e
Status ListDelete(StaticLinkList L, int i)
{
    int j, k;
    if (i < 1 || i > ListLength(L))
        return ERROR;
    k = MAXSIZE - 1;
    for (j = 1; j <= i - 1; j++)
        k = L[k].cur;    //查找下标为i-1的元素的游标
    j = L[k].cur;        //将下标为i-1的元素的游标赋值给j
    L[k].cur = L[j].cur; //
    Free_SSL(L, j);
    return OK;
}

//将下标为k的空闲节点回收到备用链表
void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur; //把第一个元素cur值赋给要删除的分量cur
    space[0].cur = k;            //把要删除的分量下标赋值给第一个元素cur
}
