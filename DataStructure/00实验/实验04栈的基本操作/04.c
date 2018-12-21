/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *实验四栈的基本操作
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
    printf("建立栈(C)\n");
    printf("初始化栈(N)\n");
    printf("入栈元素(I)\n");
    printf("出栈元素(D)\n");
    printf("退出(E)\n");
    printf("**************\n");
    do
    {
        printf("输入要做的操作:");
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
    printf("输入要入栈的元素以#结束:\n");
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
    printf("输入要入栈顶元素:");
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
    printf("出栈的元素为:%c\n", *--s->top);
}

void printstack_ch(hc_sqstack *s)
{
    char *t = s->top - 1;
    printf("当前栈中元素为:\n");
    while (t != s->base)
    {
        printf("%c\n", *t--);
    }
    printf("%c\n", *t);
}
