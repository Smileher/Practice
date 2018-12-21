/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *实验二顺序表的基本操作
 *****************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define LIST_INIT_SIZE 1
#define LISTINCREMENT 1

struct stu
{
    char name[6];
    char num[3];
    int cj;
};

struct sqlist
{
    struct stu *elem;
    int length;
    int listsize;
};

int main(void)
{
    struct sqlist *initlist_ch();
    void cshlist_ch(struct sqlist * l);
    void listinsert_ch(struct sqlist * l);
    void listdelete_ch(struct sqlist * l);
    void listhb_ch(struct sqlist * l1, struct sqlist * l2, struct sqlist * l3);
    struct sqlist *l1, *l2, *l3;
    char f;
    int i, k = 0;
    printf("请选择对顺序表的操作，操作菜单如下：\n");
    for (i = 0; i < 50; i++)
        printf("*");
    printf("\n建立顺序表(C)\n");
    printf("初始化顺序表(N)\n");
    printf("顺序表中插入元素(I)\n");
    printf("顺序表中删除元素(D)\n");
    printf("合并顺序表(H)\n");
    printf("退出系统(E)\n");
    for (i = 0; i < 50; i++)
        printf("*");
    do
    {
        printf("\n输入大写字母按Enter确定:");
        _flushall();
        f = getchar();
        if (f == 'C')
        {
            if (k == 0)
                l1 = initlist_ch();
            else
            {
                l2 = initlist_ch();
            }
            k++;
        }
        else if (f == 'N')
        {
            if (k == 1)
                cshlist_ch(l1);
            else
                cshlist_ch(l2);
        }
        else if (f == 'I')
        {
            if (k == 1)
                listinsert_ch(l1);
            else
                listinsert_ch(l2);
        }
        else if (f == 'D')
        {
            if (k == 1)
                listdelete_ch(l1);
            else
                listdelete_ch(l2);
        }
        else if (f == 'H')
        {
            l3 = initlist_ch();
            listhb_ch(l1, l2, l3);
        }
    } while (f != 'E');
}

struct sqlist *initlist_ch()
{
    struct sqlist *l;
    l = (struct sqlist *)malloc(sizeof(struct sqlist));
    if (!l)
        printf("出错!\n");
    return (l);
}

void cshlist_ch(struct sqlist *l)
{
    struct stu *newbase;
    void printlist_ch(struct sqlist * l);
    char x[6], y[3];
    int z;
    l->elem = (struct stu *)malloc(LIST_INIT_SIZE * sizeof(struct stu));
    if (!l->elem)
        printf("出错!\n");
    l->length = 0;
    l->listsize = LIST_INIT_SIZE;
    printf("请输入信息以-1结束:\n");
    scanf("%s %s %d", x, y, &z);
    while (z != -1)
    {
        if (l->length == l->listsize)
        {
            newbase = (struct stu *)realloc(l->elem, (l->listsize + LISTINCREMENT) * sizeof(struct stu));
            if (!newbase)
                printf("出错!\n");
            l->elem = newbase;
            l->listsize += LISTINCREMENT;
        }
        strcpy(l->elem[l->length].name, x);
        strcpy(l->elem[l->length].num, y);
        l->elem[l->length].cj = z;
        scanf("%s %s %d", x, y, &z);
        if (z != -1)
            l->length++;
    }
    printlist_ch(l);
}

void listinsert_ch(struct sqlist *l)
{
    int i, j;
    struct stu *newbase;
    void printlist_ch(struct sqlist * l);
    if (l->length == l->listsize)
    {
        newbase = (struct stu *)realloc(l->elem, (l->listsize + LISTINCREMENT) * sizeof(struct stu));
        if (!newbase)
            printf("出错!\n");
        l->elem = newbase;
        l->listsize += LISTINCREMENT;
    }
    printf("输入要插入信息的位置:");
    scanf("%d", &j);
    j--;
    for (i = l->length; i >= j; i--)
    {
        strcpy(l->elem[i + 1].name, l->elem[i].name);
        strcpy(l->elem[i + 1].num, l->elem[i].num);
        l->elem[i + 1].cj = l->elem[i].cj;
    }
    printf("输入插入信息:\n");
    scanf("%s %s %d", l->elem[j].name, l->elem[j].num, &l->elem[j].cj);
    l->length++;
    printlist_ch(l);
}

void listdelete_ch(struct sqlist *l)
{
    void printlist_ch(struct sqlist * l);
    int i, j;
    printf("输入删除信息的位置:");
    scanf("%d", &j);
    j--;
    printf("删除的信息为:%s,%s,%d\n", l->elem[j].name, l->elem[j].num, l->elem[j].cj);
    for (i = j + 1; i <= l->length; i++)
    {
        strcpy(l->elem[i - 1].name, l->elem[i].name);
        strcpy(l->elem[i - 1].num, l->elem[i].num);
        l->elem[i - 1].cj = l->elem[i].cj;
    }
    l->length--;
    printlist_ch(l);
}

void listhb_ch(struct sqlist *l1, struct sqlist *l2, struct sqlist *l3)
{
    void printlist_ch(struct sqlist * l);
    struct stu *p1, *p2, *p3;
    struct stu *p1_last, *p2_last;
    p1 = l1->elem;
    p2 = l2->elem;
    l3->length = l1->length + l2->length + 1;
    l3->listsize = l1->length + l2->length + 2;
    p3 = l3->elem = (struct stu *)malloc(l3->listsize * sizeof(struct stu));
    if (!l3->elem)
        printf("出错!\n");
    p1_last = l1->elem + l1->length;
    p2_last = l2->elem + l2->length;
    while (p1 <= p1_last && p2 <= p2_last)
    {
        if (p1->cj > p2->cj)
        {
            strcpy(p3->name, p1->name);
            strcpy(p3->num, p1->num);
            p3->cj = p1->cj;
            p1++;
            p3++;
        }
        else
        {
            strcpy(p3->name, p2->name);
            strcpy(p3->num, p2->num);
            p3->cj = p2->cj;
            p2++;
            p3++;
        }
    }
    while (p1 <= p1_last)
    {
        strcpy(p3->name, p1->name);
        strcpy(p3->num, p1->num);
        p3->cj = p1->cj;
        p1++;
        p3++;
    }
    while (p2 <= p2_last)
    {
        strcpy(p3->name, p2->name);
        strcpy(p3->num, p2->num);
        p3->cj = p2->cj;
        p2++;
        p3++;
    }
    printlist_ch(l3);
}

void printlist_ch(struct sqlist *l)
{
    int i;
    printf("当前表中信息如下:\n");
    for (i = 0; i <= l->length; i++)
    {
        printf("%s,%s,%d\n", l->elem[i].name, l->elem[i].num, l->elem[i].cj);
    }
}
