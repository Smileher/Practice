/*****************
 *�༶��16��ת��
 *�������º�
 *ѧ�ţ�20160566140
 *ʵ����������Ļ�������
 *****************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define LEN sizeof(struct lnode_ch)
#define LEN1 sizeof(struct hc_stu)

struct hc_stu
{
    char name[3];
    char num[3];
    int cj;
};

struct lnode_ch
{
    struct hc_stu *data;
    struct lnode_ch *next;
};

void main()
{
    struct lnode_ch *jll();
    void cshl(struct lnode_ch * head);
    void crl(struct lnode_ch * head);
    void scl(struct lnode_ch * head);
    void hbl(struct lnode_ch * h1, struct lnode_ch * h2, struct lnode_ch * h3);
    struct lnode_ch *h1, *h2, *h3;
    char f;
    int i, k = 0;
    printf("��ѡ�������Ĳ����������˵����£�\n");
    for (i = 0; i < 40; i++)
        printf("*");
    printf("\n��������(C)\n");
    printf("��ʼ������(N)\n");
    printf("�����в���Ԫ��(I)\n");
    printf("������ɾ��Ԫ��(D)\n");
    printf("�ϲ�����(H)\n");
    printf("�˳�ϵͳ(E)\n");
    for (i = 0; i < 40; i++)
        printf("*");
    do
    {
        printf("\n�����д��ĸ��Enterȷ��:");
        _flushall();
        f = getchar();
        if (f == 'C')
        {
            if (k == 0)
                h1 = jll();
            else
                h2 = jll();
            k++;
        }
        else if (f == 'N')
        {
            if (k == 1)
                cshl(h1);
            else
                cshl(h2);
        }
        else if (f == 'I')
        {
            if (k == 1)
                crl(h1);
            else
                crl(h2);
        }
        else if (f == 'D')
        {
            if (k == 1)
                scl(h1);
            else
                scl(h2);
        }
        else if (f == 'H')
        {
            h3 = jll();
            hbl(h1, h2, h3);
        }
    } while (f != 'E');
}

struct lnode_ch *jll()
{
    struct lnode_ch *head;
    head = (struct lnode_ch *)malloc(LEN);
    if (!head)
        printf("����!\n");
    head->next = NULL;
    return (head);
}

void cshl(struct lnode_ch *head)
{
    void printl(struct lnode_ch * head);
    char x[3], y[3];
    int z;
    struct lnode_ch *p1 = head, *p2;
    printf("��������Ϣ��-1����:\n");
    scanf("%s %s %d", x, y, &z);
    while (z != -1)
    {
        p2 = (struct lnode_ch *)malloc(LEN);
        if (!p2)
            printf("����!\n");
        p2->data = (struct hc_stu *)malloc(LEN1);
        if (!p2->data)
            printf("����!\n");
        strcpy(p2->data->name, x);
        strcpy(p2->data->num, y);
        p2->data->cj = z;
        p2->next = NULL;
        p1->next = p2;
        p1 = p2;
        scanf("%s %s %d", x, y, &z);
    }
    printl(head);
}

void crl(struct lnode_ch *head)
{
    void printl(struct lnode_ch * head);
    int j;
    struct lnode_ch *p, *p1 = head;
    printf("������Ҫ������Ϣ��λ��:");
    scanf("%d", &j);
    while (j-- > 1)
        p1 = p1->next;
    p = (struct lnode_ch *)malloc(LEN);
    if (!p)
        printf("����!\n");
    p->data = (struct hc_stu *)malloc(LEN1);
    if (!p->data)
        printf("����!\n");
    printf("������Ҫ�������Ϣ:\n");
    scanf("%s %s %d", p->data->name, p->data->num, &p->data->cj);
    p->next = p1->next;
    p1->next = p;
    printl(head);
}

void scl(struct lnode_ch *head)
{
    void printl(struct lnode_ch * head);
    int j;
    struct lnode_ch *p1 = head, *p2 = head->next;
    printf("������Ҫɾ����Ϣ��λ��:");
    scanf("%d", &j);
    while (j > 1)
    {
        p1 = p1->next;
        p2 = p2->next;
        j--;
    }
    printf("ɾ������ϢΪ:%s,%s,%d\n", p2->data->name, p2->data->num, p2->data->cj);
    p1->next = p2->next;
    free(p2);
    printl(head);
}

void hbl(struct lnode_ch *h1, struct lnode_ch *h2, struct lnode_ch *h3)
{
	void printl(struct lnode_ch *head); 
    struct lnode_ch *p1, *p2, *p3;
    p1 = h1->next;
    p2 = h2->next;
    h3 = p3 = h1;
    while (p1 && p2)
    {
        if (p1->data->cj > p2->data->cj)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3->next = p1 ? p1 : p2;
    free(h2);
    printl(h3);
}

void printl(struct lnode_ch *head)
{
    struct lnode_ch *p = head->next;
    printf("��ǰ����Ԫ������:\n");
    while (p->next != NULL)
    {
        printf("%s,%s,%d\n", p->data->name, p->data->num, p->data->cj);
        p = p->next;
    }
    printf("%s,%s,%d\n", p->data->name, p->data->num, p->data->cj);
}
