/*****************
 *�༶��16��ת��
 *�������º�
 *ѧ�ţ�20160566140
 *ʵ����ջ�Ļ�������
 *****************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define STACK_INIT_SIZE 1
#define STACKINCREMENT 1
#define ERROR 0

typedef struct
{
    char *base;
    char *top;
    int stacksize;
} hc_sqstack;

int main(void)
{
    hc_sqstack *initstack_ch();
    void cshstack_ch(hc_sqstack * s);
    void push_ch(hc_sqstack * s);
    void pop_ch(hc_sqstack * s);
    void printstack_ch(hc_sqstack * s);
    hc_sqstack *s;
    char f;
    printf("**************\n");
    printf("����ջ(C)\n");
    printf("��ʼ��ջ(N)\n");
    printf("��ջԪ��(I)\n");
    printf("��ջԪ��(D)\n");
    printf("�˳�(E)\n");
    printf("**************\n");
    do
    {
        printf("����Ҫ���Ĳ���:");
        _flushall();
        f = getchar();
        if (f == 'C')
            s = initstack_ch();
        else if (f == 'I')
        {
            push_ch(s);
            printstack_ch(s);
        }
        else if (f == 'N')
        {
            cshstack_ch(s);
            printstack_ch(s);
        }
        else if (f == 'D')
        {
            pop_ch(s);
            printstack_ch(s);
        }
    } while (f != 'E');
}

hc_sqstack *initstack_ch()
{
    hc_sqstack *s;
    s = (hc_sqstack *)malloc(sizeof(hc_sqstack));
    if (!s)
        exit(ERROR);
    return (s);
}

void cshstack_ch(hc_sqstack *s)
{
    char e;
    s->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
    if (!s->base)
        exit(ERROR);
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    printf("����Ҫ��ջ��Ԫ����#����:\n");
    _flushall();
    e = getchar();
    while (e != '#')
    {
        if (s->top - s->base >= s->stacksize)
        {
            s->base = (char *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(char));
            if (!s->base)
                exit(ERROR);
            s->top = s->base + s->stacksize;
            s->stacksize += STACKINCREMENT;
        }
        *s->top++ = e;
        _flushall();
        e = getchar();
    }
}

void push_ch(hc_sqstack *s)
{
    char e;
    printf("����Ҫ��ջ��Ԫ��:");
    _flushall();
    e = getchar();
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (char *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(char));
        if (!s->base)
            exit(ERROR);
        s->top = s->base + s->stacksize;
        s->stacksize += STACKINCREMENT;
    }
    *s->top++ = e;
}

void pop_ch(hc_sqstack *s)
{
    if (s->top == s->base)
        exit(ERROR);
    printf("��ջ��Ԫ��Ϊ:%c\n", *--s->top);
}

void printstack_ch(hc_sqstack *s)
{
    char *t = s->top - 1;
    printf("��ǰջ��Ԫ��Ϊ:\n");
    while (t != s->base)
    {
        printf("%c\n", *t--);
    }
    printf("%c\n", *t);
}
