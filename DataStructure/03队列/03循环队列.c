//为了改善顺序队列的缺点，我们把队列的首位相连，形成循环队列
//这样每次入队出队只需要灵活的改变front和rear指针即可
//也就是让front或rear指针不断加1，即使超出了地址范围，也会自动从头开始
//我们可以采取去摸运算处理：
//-(rear+1)%QueueSize
//-(front+1)%QueueSize
//取模就是取余数的意思，它取到的值永远不会大于除数
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
#define MAXSIZE 100
//定义一个循环队列
typedef struct
{
    ElemType *base; //用于存放内存分配基地址
                    //这里也可以用于数组存放
    int front;
    int rear;
} cycleQueue;
//初始化队列
InitQueue(cycleQueue *q)
{
    //分配一个ElemType大小×最大容量的内存空间，且q->base指向首地址
    q->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if (!q->base)         //如果分配失败
        exit(0);            //退出
    q->front = q->rear = 0; //队首、队尾指针相等为0
}
//入队 从队尾入
InsertQueue(cycleQueue *q, ElemType e)
{
    //尾指针+1等于头指针，再取余，如果与头指针相等则队列已满
    if ((q->rear + 1) % MAXSIZE == q->front)
        return;
    q->base[q->rear] = e;              //把e赋值给数组base队尾位置的数据
    q->rear = (q->rear + 1) % MAXSIZE; //尾指针如果超过了MAXSIZE则从新开始
}
//出队 从队头出
DeleteQueue(cycleQueue *q, ElemType *e)
{
    if (q->front == q->rear) //队列为空
        return;
    *e = q->base[q->front];              //把数组base队头位置的数据赋值给e
    q->front = (q->front + 1) % MAXSIZE; //头指针如果超过了MAXSIZE则从新开始
}
int main(void)
{
    return 0;
}