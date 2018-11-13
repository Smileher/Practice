#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 11 //��ʼ����

typedef int Status;
typedef int QElemType; //������������

//ѭ�����е�˳��洢�ṹ
typedef struct
{
    QElemType data[MAXSIZE];
    int front; //ͷָ��
    int rear;  //βָ�룬���зǿ�ʱ��ָ���βԪ�ص���һ��λ��
} SqQueue;

Status visit(QElemType item)
{
    printf("%d", item);
    return OK;
}

//��ʼ���ն���
Status InitQueue(SqQueue *sQ)
{
    sQ->front = 0;
    sQ->rear = 0;
    return OK;
}

//���������
Status ClearQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0;
    return OK;
}

//�ж϶����Ƿ�Ϊnull
Status QueueEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

//���ض����е�Ԫ�ظ���
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//���ض�ͷԪ��
Status GetHead(SqQueue Q, QElemType *e)
{
    if (Q.front == Q.rear) //�Ƿ�Ϊ�ն���
        return ERROR;
    *e = Q.data[Q.front];
    return OK;
}

//�ڶ�β����Ԫ��
Status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front) //��������
        return ERROR;

    Q->data[Q->rear] = e;              //�����β
    Q->rear = (Q->rear + 1) % MAXSIZE; //β��ָ����ƣ�����������ת��ͷ��
    return OK;
}

//Ԫ�س���
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear) //���п�
        return ERROR;
    *e = Q->data[Q->front];              //���ض�ͷԪ��
    Q->front = (Q->front + 1) % MAXSIZE; //��ͷָ����ƣ��絽���ת��ͷ��
    return OK;
}

//��������Ԫ��
Status QueueTraverse(SqQueue Q)
{
    int i = Q.front;
    while ((i + Q.front) != Q.rear)
    {
        visit(Q.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
    return OK;
}

int main()
{

    Status j;
    int i = 0, l;
    QElemType d;
    SqQueue Q;
    InitQueue(&Q);

    //��ӣ�����Ԫ��
    for (int i = 0; i < MAXSIZE - 1; i++)
    {
        EnQueue(&Q, i);
    }
    QueueTraverse(Q);

    printf("���γ���:");
    for (l = 1; l <= MAXSIZE; l++)
    {
        DeQueue(&Q, &d);
        printf("d= %d,", d);
    }

    return 0;
}