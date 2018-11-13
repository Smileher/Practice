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

typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
//����ʽ���е�ͷβ���ָ�붨���Ϊһ�������Ľṹ��,�����������ڵ�ʱռ�ù���Ŀռ�
typedef struct
{
    QueuePtr front, rear; //��ͷָ��ָ�������е�ͷָ�� ��βָ��ָ�������е��ն˽ڵ�
} LinkQueue;
//�ն���ʱ fornt��rear��ָ��ͷ���
//��ʼ������
InitQueue(LinkQueue *q)
{
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); //��ͷ��βָ��ͬʱָ��һ�����
    if (!q->front)
        exit(0);           //����ʧ�ܣ��˳�
    q->front->next = NULL; //ͷ���տ�ʼָ��NULL
}
//����� �ڶ�β����
InsertQueue(LinkQueue *q, ElemType e)
{
    QueuePtr p; //Ҫ����еĽ��p
    p = (QueuePtr)malloc(sizeof(QNode));
    if (p == NULL)
        exit(0);
    p->data = e;       //��Ҫ����е�Ԫ��e��ֵ���½��p��������
    p->next = NULL;    //�½��p��ָ����ΪNULL
    q->rear->next = p; //���е��ն˵Ľ��ָ��p
    q->rear = p;       //�������¶����ն˱�Ϊp
}
//������ �ڶ�ͷɾ��
DeleteQueue(LinkQueue *q, ElemType *e)
{
    QueuePtr p;               //�½�һ�����p p���汻��ֵΪ�����ӵĽ��
    if (q->front == q->rear)  //���Ϊ�ն���
        return;               //��ֹ����
    p = q->front->next;       //��ͷ������һ�����(Ҫ���ӵĽ��)��ֵ��p
    *e = p->data;             //��p��������ֵ��e
    q->front->next = p->next; //ͷ������ָ��Ľ������Ϊp����һ�����
    if (q->rear == p)         //�����βָ����p(����ֻ��һ��Ԫ�ص������)
        q->rear = q->front;   //������к�Ķ���Ϊ�ն���(��βָ���ͷ)
    free(p);                  //�ͷ�p
}
//���ٶ��� ÿ���ͷŶ�ͷ���
//���������н������ڴ�Ķ�̬��
//��˵����в�������ʱӦ��ʱ���ٵ�
//��������ռ���ڴ�ռ�
DestroyQueue(LinkQueue *q)
{
    while (q->front) //�����е�ͷ������ʱ
    {
        q->rear = q->front->next; //β���ָ��ͷ������һ�����
        free(q->front);           //�ͷ�ͷ���
        q->front = q->rear;       //ͷ���ָ��β���
    }
}
int main(void)
{
    return 0;
}