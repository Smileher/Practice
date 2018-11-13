//顺序栈实现二进制转十进制
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20 //栈的默认空间
#define STACKINCREMENT 10  //栈的默认空间不够时的每次增加的空间

typedef char ElemType;

//定义栈
typedef struct
{
    ElemType *base; //栈底
    ElemType *top;  //栈顶
    int stackSize;  //栈的容量
} sqStack;

//初始化栈
void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType)); //为栈底分配一个 ElemType类型大小*默认容量 的空间
    if (!s->base)                                                     //判断是否成功分配空间。如果栈底没有分配成功则退出
    {
        exit(0);
    }
    s->top = s->base;               //初始化时为空栈，把栈底赋值给栈顶
    s->stackSize = STACK_INIT_SIZE; //栈的容量为默认容量
}

//入栈
void Push(sqStack *s, ElemType e)
{
    if (s->top - s->base >= s->stackSize) //判断栈是否满。栈顶地址-栈底地址=栈目前的容量，如果栈目前的容量大于等于栈的默认容量则栈满，需要增加容量
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType)); //动态内存调整：realloc(要改变内存大小的指针名，新的大小)
        if (!s->base)                                                                               //判断是否成功分配空间。如果栈底没有分配成功则退出
        {
            exit(0);
        }
    }
    *(s->top) = e; //把入栈的元素赋值给栈顶
    s->top++;
}

//出栈
void Pop(sqStack *s, ElemType *e)
{
    if (s->base == s->top) //判断是否为空栈
    {
        return;
    }
    *e = *--(s->top); //先把栈顶指针-1并取值，再赋值给e
}
//求栈目前的容量
int StackLen(sqStack s)
{
    return (s.top - s.base); //栈顶地址-栈底地址=栈目前的容量
}

int main(void)
{
    sqStack s;           //定义一个栈s
    ElemType c;          //定义一个与栈s元素相同类型的变量c
    int len, i, sum = 0; //栈的容量len
    InitStack(&s);       //初始化栈
    printf("请输入二进制数，输入#符号表示结束\n");
    scanf("%c", &c); //输入元素
    while (c != '#')
    {
        Push(&s, c);     //入栈
        scanf("%c", &c); //输入元素
    }
    getchar(); //把'\n'从键盘的缓冲区清除

    len = StackLen(s); //求栈目前的容量
    printf("栈的当前容量是：%d\n", len);
    for (i = 0; i < len; i++)
    {
        Pop(&s, &c);                      //出栈
        sum = sum + (c - 48) * pow(2, i); //每次出栈的元素*2^i并相加求和
    }
    printf("转化为十进制数是：%d\n", sum);
    return 0;
}
