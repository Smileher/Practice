#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    SElemType data;         //数据域
    struct StackNode *next; //指针域
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top; //top指针指向栈的元素data
    int count;        //栈元素的计数器
} LinkStack;

//进栈
//元素为e的新结点是s，插入元素e为新的栈顶元素
Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top; //把当前的栈元素赋值给新结点的直接后继
    //可以理解成新结点s的指针域指向插入前栈S的top结点
    S->top = s; //将新的结点s赋值给栈顶指针，插入e后的栈S的top结点为s
    //可以理解成栈顶指针S->top现在指向了新插入的结点s
    S->count++;
    return OK;
}

//出栈
//用变量p来存储要删除的栈顶结点，将栈顶指针下移一位，最后释放p
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;     //p为待删除的结点
    if (StackEmpty(*S)) //判断是否为空栈
        return ERROR;
    *e = S->top->data;     //把栈顶元素的数据域赋值给e
    S->top = S->top->next; //栈顶指针下移一位，指向删除前的栈顶的后一结点
    free(p);               //释放p
    S->count--;
    return OK;
}