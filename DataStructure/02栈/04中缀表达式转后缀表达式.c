//中缀表达式转后缀表达式
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
    sqStack s;     //定义一个栈s
    char c, e;     //定义成char类型方便分离每一个元素
    InitStack(&s); //初始化栈
    printf("请输入一个中缀表达式，输入#符号表示结束\n");
    scanf("%c", &c); //输入元素
    //如果输入的不是#，一个一个的遍历并判断是输出还是入栈出栈，分为以下5种情况
    while (c != '#')
    {
        //1如果遍历到的是数字，则输出(如果连续输出多个数字时，仅最后一个数字前加空格)
        while (c >= '0' && c <= '9')
        {
            printf("%c", c);        //输出
            scanf("%c", &c);        //再次输入新的元素c,此时并没有再次判断是否是#，故后面需再次判断
            if (c < '0' || c > '9') //如果新输入的元素c不是数字
            {
                printf(" ");
            }
        }
        //2如果遍历到的是右括号")"，则一直出栈并输出，直到出栈的是左括号"("，左括号只出栈不输出
        if (')' == c)
        {
            Pop(&s, &e); //出栈
            //如果出栈的元素不是左括号，则循环输出，循环出栈，直到出栈的是左括号(输出和出栈两括号之间的元素)
            while ('(' != e) //如果出栈的元素不是左括号
            {
                printf("%c ", e); //输出元素
                Pop(&s, &e);      //出栈，并通过while循环再次判断，直到出栈的是左括号
            }
        }
        //如果遍历到的是符号("+","-","*","/")，则比较当前遍历到的元素(符号)与栈顶元素的优先级
        //如果当前遍历到的元素(符号)的优先级高于栈顶元素则入栈；
        //低于或等于栈顶元素(符号)的优先级或者栈顶元素是右括号则出栈
        //经过分析，则会发现只要当前遍历到的元素(符号)是'+'或'-'
        //无论栈底元素是什么元素，当前遍历到的元素(符号)都不入栈，栈顶元素出栈，再次进行比较

        //3如果遍历到的是'+'或'-'，则判断若是空栈，进栈；若不是空栈，则判断栈顶元素的优先级
        else if ('+' == c || '-' == c)
        {
            if (!StackLen(s)) //如果是空栈
                Push(&s, c);  //则当前遍历到的元素(符号)入栈
            else              //如果不是空栈
            {
                do
                {
                    Pop(&s, &e); //栈顶元素e出栈，并进行如下的比较
                    //如果出栈的元素e是左括号'('，则左括号'('再入栈
                    if ('(' == e)
                    {
                        Push(&s, e);
                    }
                    //如果出栈的元素e是"+","-","*","/"，则输出出栈的元素e
                    else
                    {
                        printf("%c ", e);
                    }
                } while (StackLen(s) && '(' != e); //当栈不为空且出栈的元素e不为左括号'('时,循环进行如上操作
                                                   //直到栈的元素都出栈变为空栈或者遇到左括号'('时，循环终止
                Push(&s, c);                       //循环跳出，排除以上可能性，最终时遇到左括号'('时，当前遍历到的元素c入栈
            }
        }
        //4如果是"*","/",'('，则直接入栈
        else if ('*' == c || '/' == c || '(' == c)
        {
            Push(&s, c);
        }
        //这里是判断第1种情况while循环里的再次输入是否为#
        else if ('#' == c)
        {
            break;
        }
        else
        //5如果以上的情况都不满足，则提示错误
        {
            printf("\n输入格式错误！\n");
            return -1;
        }
        scanf("%c", &c); //循环输入新的元素c并且重复以上的判断和循环
    }
    while (StackLen(s)) //如果栈不为空，则依次出栈并输出
    {
        Pop(&s, &e);
        printf("%c ", e);
    }
    return 0;
}
