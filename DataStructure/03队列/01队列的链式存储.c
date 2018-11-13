#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType; //定义数据类型

typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
//当链式队列的头尾结点指针定义成为一个单独的结构体,避免在新增节点时占用过多的空间
typedef struct
{
    QueuePtr front, rear; //队头指针指向链队列的头指针 队尾指针指向链队列的终端节点
} LinkQueue;
//空队列时 fornt和rear都指向头结点
//初始化队列
InitQueue(LinkQueue *q)
{
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); //队头队尾指针同时指向一个结点
    if (!q->front)
        exit(0);           //分配失败，退出
    q->front->next = NULL; //头结点刚开始指向NULL
}
//入队列 在队尾插入
InsertQueue(LinkQueue *q, ElemType e)
{
    QueuePtr p; //要入队列的结点p
    p = (QueuePtr)malloc(sizeof(QNode));
    if (p == NULL)
        exit(0);
    p->data = e;       //把要入队列的元素e赋值给新结点p的数据域
    p->next = NULL;    //新结点p的指针域为NULL
    q->rear->next = p; //队列的终端的结点指向p
    q->rear = p;       //插入后的新队列终端变为p
}
//出队列 在队头删除
DeleteQueue(LinkQueue *q, ElemType *e)
{
    QueuePtr p;               //新建一个结点p p下面被赋值为待出队的结点
    if (q->front == q->rear)  //如果为空队列
        return;               //终止操作
    p = q->front->next;       //把头结点的下一个结点(要出队的结点)赋值给p
    *e = p->data;             //把p的数据域赋值给e
    q->front->next = p->next; //头结点的所指向的结点现在为p的下一个结点
    if (q->rear == p)         //如果队尾指针是p(队列只有一个元素的情况下)
        q->rear = q->front;   //则出队列后的队列为空队列(队尾指向队头)
    free(p);                  //释放p
}
//销毁队列 每次释放队头结点
//由于链队列建立在内存的动态区
//因此当队列不再有用时应及时销毁掉
//以免过多的占用内存空间
DestroyQueue(LinkQueue *q)
{
    while (q->front) //当队列的头结点存在时
    {
        q->rear = q->front->next; //尾结点指向头结点的下一个结点
        free(q->front);           //释放头结点
        q->front = q->rear;       //头结点指向尾结点
    }
}
int main(void)
{
    return 0;
}