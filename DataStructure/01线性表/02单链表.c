//若线性表需要频繁查找，很少进行插入和删除操作时，宜采用顺序存储结构
//若需要频繁插入和删除时，宜采用单链表结构
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE
typedef int ElemType;
typedef int Status;

//描述一个结点
typedef struct Node
{
    ElemType data;     //数据域
    struct Node *next; //指针域
} Node;
//把struct Node*定义成了新类型LinkList 指向一个结点的指针 结构体指针
typedef struct Node *LinkList; //LinkList 等同于 Node*

//GetElem获取元素
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;  //定义一个指针p
    p = L->next; //p指向链表的第一个结点
    j = 1;
    while (p && j < i) //链表不为空且没找到这个元素
    {
        p = p->next; //不断指向下一个结点
        ++j;
    }
    if (!p || j > i) //!p 链表为空 指向最后一个元素
        return ERROR;
    *e = p->data;
    return OK;
}

//ListInsert插入
Status LinkInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s; //s是待插入的结点 Node* s;
    p = *L;        //声明结点p 指向链表L的头节点
    j = 1;
    while (p && j < i) //遍历链表 用于寻找第i个结点
    {
        p = p->next; //不断指向下一个结点
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;       //将待插入的元素赋值给s的数据域
    s->next = p->next; //s的指针域指向p的下一个元素
    p->next = s;       //p的指针域指向s
    return OK;
}

//ListDelete删除
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q; //q是待删除结点
    p = *L;        //声明结点p 指向链表L的头节点
    j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i) //j>i的情况?
        return ERROR;
    q = p->next;       //将待删除结点p->next赋值给q
    p->next = q->next; //p的指针域指向q的下一个元素
    *e = q->data;      //将待删除结点q的数据域赋值给e
    free(q);           //释放q结点
    return OK;
}
//创建单链表的过程是一个动态生成链表的过程
//从“空表”的初始状态起，依次建立各个元素结点并逐个插入链表
//头插法建立单链表
void CreateListHead(LinkList *L, int n)
{
    LinkList p; //p为每一次被赋值的新的结点
    int i;

    srand(time(0)); //用当前时间来作为初始化随机数种子
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL; //L为头节点，初始化指向NULL
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1; //rand()%100表示0~99的随机数
        p->next = (*L)->next;       //p的指针域指向L的下一个结点
        (*L)->next = p;             //L的指针域指向结点p
    }
}
//尾插法建立单链表
void CreateListTail(LinkList *L, int n)
{
    LinkList p, r; //p是新节点 r是尾结点
    int i;

    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L; //r指向单链表L(此时为空表)的表头

    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        r->next = p; //将尾结点r的指针域指向新结点p
        r = p;       //此时尾结点是新节点p，将尾结点赋值为r以便下次重复使用
    }
    r->next = NULL; //表尾指向NULL
}
//单链表的整表删除
//声明结点p和q
//将第一个结点赋值给p，下一个结点赋值给q
//循环执行释放和将q赋值给p的操作
Status ClearList(LinkList *L)
{
    LinkList p, q;
    int i;
    p = (*L)->next; //将p指向单链表L的第一个结点
    while (p)       //如果p不为NULL(有数据)时
    {
        q = p->next; //第一个结点p指针域赋值给第二个结点q
        free(p);     //释放第一个结点p
        p = q;       //第二个结点q变成第一个结点p，进行下一次循环
    }
    (*L)->next = NULL; //变成空表
    return OK;
}

int main(void)
{
    return 0;
}