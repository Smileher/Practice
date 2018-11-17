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
void InitQueue(LinkQueue *q)
{
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); //��ͷ��βָ��ͬʱָ��һ�����
    if (!q->front)
        exit(0);           //����ʧ�ܣ��˳�
    q->front->next = NULL; //ͷ���տ�ʼָ��NULL
}
//����� �ڶ�β����
void InsertQueue(LinkQueue *q, ElemType e)
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
void DeleteQueue(LinkQueue *q, ElemType *e)
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
void DestroyQueue(LinkQueue *q)
{
    while (q->front) //�����е�ͷ������ʱ
    {
        q->rear = q->front->next; //β���ָ��ͷ������һ�����
        free(q->front);           //�ͷ�ͷ���
        q->front = q->rear;       //ͷ���ָ��β���
    }
}
//�ж϶����Ƿ�Ϊ��
Status isEmpty(LinkQueue *q)
{
    if (q->front == q->rear)
        return TRUE;
    else
        return FALSE;
}
//����г���
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
//��������
void TraverseQueue(LinkQueue *q, void (*print)(ElemType))
{
    QueuePtr p = q->front->next; //��ͷ��㣬����Ҫָ����һ��
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
    printf("���������Ĳ�����\n");
    printf("***********************************\n");
    printf("\t1)��ʼ������\n");
    printf("\t2)������\n");
    printf("\t3)�����Ƿ�ǿ�\n");
    printf("\t4)����еĳ���\n");
    printf("\t5)������е�Ԫ��\n");
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
            printf("��ʼ�����гɹ�!��������������Ĳ�����\n");
        }
        if (2 == key)
        {
            ElemType e;
            printf("����������е�Ԫ�أ���-1��β\n");
            scanf("%d", &e);
            while (e != -1)
            {
                InsertQueue(&q, e);
                scanf("%d", &e);
            }
            printf("\n��������ɹ���������������Ĳ�����\n");
        }
        if (3 == key)
        {
            if (isEmpty(&q))
                printf("����Ϊ�գ�");
            else
                printf("���зǿգ�");
            printf("������������Ĳ�����\n");
        }
        if (4 == key)
        {
            printf("���г���Ϊ%d��������������Ĳ�����\n", QueueLength(&q));
        }
        if (5 == key)
        {
            printf("�������е�Ԫ��Ϊ��");
            TraverseQueue(&q, visit);
            printf("\nִ����ϣ����������Ĳ�����\n");
        }
        scanf("%d", &key);
        continue;
    }
    return 0;
}
