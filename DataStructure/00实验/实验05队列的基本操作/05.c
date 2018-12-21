/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *实验五队列的基本操作
 *****************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAXQSIZE 5
#define ERROR 0
#define OK 1

typedef struct
{
    char *base;
    int front;
    int rear;
    int length;
} ch_sqqueue;

int main(void)
{
    ch_sqqueue *initqueue_ch();
    int cshqueue_ch(ch_sqqueue * q);
    int enqeue_ch(ch_sqqueue * q, char e);
    int deqeue_ch(ch_sqqueue * q);
    int printqueue_ch(ch_sqqueue * q);
    ch_sqqueue *q;
    char f, e;
    printf("***************\n");
    printf("建立队列(C)\n");
    printf("初始化队列(N)\n");
    printf("入队列元素(I)\n");
    printf("出队列元素(D)\n");
    printf("退出(E)\n");
    printf("***************\n");
    do
    {
        printf("输入要做的操作:");
        _flushall();
        f = getchar();
        if (f == 'C')
            q = initqueue_ch();
        else if (f == 'N')
        {
            cshqueue_ch(q);
            printqueue_ch(q);
        }
        else if (f == 'I')
        {
            printf("输入要的入队的元素:");
            _flushall();
            e = getchar();
            enqeue_ch(q, e);
            printqueue_ch(q);
        }
        else if (f == 'D')
        {
            deqeue_ch(q);
            printqueue_ch(q);
        }
    } while (f != 'E');
}
ch_sqqueue *initqueue_ch()
{
    ch_sqqueue *q;
    q = (ch_sqqueue *)malloc(sizeof(ch_sqqueue));
    if (!q)
        exit(ERROR);
    return (q);
}

int cshqueue_ch(ch_sqqueue *q)
{
    char e;
    int enqeue_ch(ch_sqqueue * q, char e);
    q->base = (char *)malloc(MAXQSIZE * sizeof(char));
    if (!q->base)
        exit(ERROR);
    q->front = q->rear = 0;
    q->length = 0;
    printf("输入元素以#结束:\n");
    _flushall();
    e = getchar();
    while (e != '#')
    {
        enqeue_ch(q, e);
        if (q->length == MAXQSIZE)
            return (ERROR);
        else
        {
            _flushall();
            e = getchar();
        }
    }
    return (OK);
}

int enqeue_ch(ch_sqqueue *q, char e)
{
    if (q->length == MAXQSIZE)
        return (ERROR);
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAXQSIZE;
    q->length++;
    return (OK);
}

int deqeue_ch(ch_sqqueue *q)
{
    if (q->length == 0)
        return (ERROR);
    printf("出队的元素为:%c\n", q->base[q->front]);
    q->front = (q->front + 1) % MAXQSIZE;
    q->length--;
    return (OK);
}

int printqueue_ch(ch_sqqueue *q)
{
    int t = q->front;
    if (q->length == 0)
    {
        printf("队空!\n");
        return (ERROR);
    }
    if (q->length == MAXQSIZE)
        printf("队满!\n");
    printf("当前队列中元素为:\n");
    do
    {
        printf("%c\n", q->base[t]);
        t = (t + 1) % MAXQSIZE;
    } while (t != q->rear);
    return (OK);
}
