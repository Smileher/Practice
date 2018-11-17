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
void InitQueue(LinkQueue *q)
{
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); //队头队尾指针同时指向一个结点
    if (!q->front)
        exit(0);           //分配失败，退出
    q->front->next = NULL; //头结点刚开始指向NULL
}
//入队列 在队尾插入
void InsertQueue(LinkQueue *q, ElemType e)
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
void DeleteQueue(LinkQueue *q, ElemType *e)
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
void DestroyQueue(LinkQueue *q)
{
    while (q->front) //当队列的头结点存在时
    {
        q->rear = q->front->next; //尾结点指向头结点的下一个结点
        free(q->front);           //释放头结点
        q->front = q->rear;       //头结点指向尾结点
    }
}
//判断队列是否为空
Status isEmpty(LinkQueue *q)
{
    if (q->front == q->rear)
        return TRUE;
    else
        return FALSE;
}
//求队列长度
int QueueLength(LinkQueue *q)
{
    if (q->front == NULL)
    {
        return 0;
    }
    int length = 0;
    QueuePtr p = q->front->next;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}
//遍历队列
void TraverseQueue(LinkQueue *q, void (*print)(ElemType))
{
    QueuePtr p = q->front->next; //有头结点，所以要指向下一个
    while (p)
    {
        print(p->data);
        p = p->next;
    }
}
void visit(ElemType e)
{
    printf("%d ", e);
}
void Menu()
{
    printf("请输入您的操作：\n");
    printf("***********************************\n");
    printf("\t1)初始化队列\n");
    printf("\t2)建队列\n");
    printf("\t3)队列是否非空\n");
    printf("\t4)求队列的长度\n");
    printf("\t5)输出队列的元素\n");
    printf("***********************************\n");
}
int main(void)
{
    LinkQueue q;
    ElemType e;
    int key;
    Menu();
    scanf("%d", &key);
    while (1)
    {
        if (1 == key)
        {
            InitQueue(&q);
            printf("初始化队列成功!，请继续输入您的操作：\n");
        }
        if (2 == key)
        {
            ElemType e;
            printf("请输入入队列的元素，用-1结尾\n");
            scanf("%d", &e);
            while (e != -1)
            {
                InsertQueue(&q, e);
                scanf("%d", &e);
            }
            printf("\n数据输入成功，请继续输入您的操作：\n");
        }
        if (3 == key)
        {
            if (isEmpty(&q))
                printf("队列为空！");
            else
                printf("队列非空！");
            printf("请继续输入您的操作：\n");
        }
        if (4 == key)
        {
            printf("队列长度为%d，请继续输入您的操作：\n", QueueLength(&q));
        }
        if (5 == key)
        {
            printf("队列所有的元素为：");
            TraverseQueue(&q, visit);
            printf("\n执行完毕，请输入您的操作：\n");
        }
        scanf("%d", &key);
        continue;
    }
    return 0;
}
