/*****************
 *�༶��16��ת��
 *�������º�
 *ѧ�ţ�20160566140
 *ʵ������еĻ�������
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
    printf("��������(C)\n");
    printf("��ʼ������(N)\n");
    printf("�����Ԫ��(I)\n");
    printf("������Ԫ��(D)\n");
    printf("�˳�(E)\n");
    printf("***************\n");
    do
    {
        printf("����Ҫ���Ĳ���:");
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
            printf("����Ҫ����ӵ�Ԫ��:");
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
    printf("����Ԫ����#����:\n");
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
    printf("���ӵ�Ԫ��Ϊ:%c\n", q->base[q->front]);
    q->front = (q->front + 1) % MAXQSIZE;
    q->length--;
    return (OK);
}

int printqueue_ch(ch_sqqueue *q)
{
    int t = q->front;
    if (q->length == 0)
    {
        printf("�ӿ�!\n");
        return (ERROR);
    }
    if (q->length == MAXQSIZE)
        printf("����!\n");
    printf("��ǰ������Ԫ��Ϊ:\n");
    do
    {
        printf("%c\n", q->base[t]);
        t = (t + 1) % MAXQSIZE;
    } while (t != q->rear);
    return (OK);
}
