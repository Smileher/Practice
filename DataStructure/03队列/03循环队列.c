//Ϊ�˸���˳����е�ȱ�㣬���ǰѶ��е���λ�������γ�ѭ������
//����ÿ����ӳ���ֻ��Ҫ���ĸı�front��rearָ�뼴��
//Ҳ������front��rearָ�벻�ϼ�1����ʹ�����˵�ַ��Χ��Ҳ���Զ���ͷ��ʼ
//���ǿ��Բ�ȡȥ�����㴦��
//-(rear+1)%QueueSize
//-(front+1)%QueueSize
//ȡģ����ȡ��������˼����ȡ����ֵ��Զ������ڳ���
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType; //������������
#define MAXSIZE 100
//����һ��ѭ������
typedef struct
{
    ElemType *base; //���ڴ���ڴ�������ַ
                    //����Ҳ��������������
    int front;
    int rear;
} cycleQueue;
//��ʼ������
InitQueue(cycleQueue *q)
{
    //����һ��ElemType��С������������ڴ�ռ䣬��q->baseָ���׵�ַ
    q->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if (!q->base)         //�������ʧ��
        exit(0);            //�˳�
    q->front = q->rear = 0; //���ס���βָ�����Ϊ0
}
//��� �Ӷ�β��
InsertQueue(cycleQueue *q, ElemType e)
{
    //βָ��+1����ͷָ�룬��ȡ�࣬�����ͷָ��������������
    if ((q->rear + 1) % MAXSIZE == q->front)
        return;
    q->base[q->rear] = e;              //��e��ֵ������base��βλ�õ�����
    q->rear = (q->rear + 1) % MAXSIZE; //βָ�����������MAXSIZE����¿�ʼ
}
//���� �Ӷ�ͷ��
DeleteQueue(cycleQueue *q, ElemType *e)
{
    if (q->front == q->rear) //����Ϊ��
        return;
    *e = q->base[q->front];              //������base��ͷλ�õ����ݸ�ֵ��e
    q->front = (q->front + 1) % MAXSIZE; //ͷָ�����������MAXSIZE����¿�ʼ
}
int main(void)
{
    return 0;
}