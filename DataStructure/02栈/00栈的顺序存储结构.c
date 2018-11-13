#include <stdio.h>
#define StackSize 100
#define MAXSIZE 100
#define ERROR 0
#define OK 1
#define Status int
//栈的结构定义 表头是栈底，表尾是栈顶
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
} SqStack;

//进栈 插入元素e为新的栈顶元素
Status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1) //栈满
        return ERROR;
    S->top++;            //栈顶指针增加1
    S->data[S->top] = e; //将新插入元素值给栈顶空间
    return OK;
}
//出栈 将栈底元素赋值给e并删除
//若栈不为空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1) //为空栈
        return ERROR;
    *e = S->data[S->top]; //将要删除的栈顶元素赋值给e
    S->top--;             //栈顶指针减1
    return OK;
}

int main()
{
    return 0;
}