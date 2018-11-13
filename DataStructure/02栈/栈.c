#include <stdio.h>
#include <stdlib.h>

/*堆栈的基本操作*/
struct Stack
{
    int data;
    struct Stack *next;
};
typedef struct Stack *link;
typedef struct Stack Snode;

/*初始化栈*/
link init()
{
    link p;
    p = (link)malloc(sizeof(Snode));
    p = NULL;
    return p;
}
/*入栈*/
link push(link Head, int x)
{
    link p;
    p = (link)malloc(sizeof(Snode));
    if (p == NULL)
    {
        printf("分配内存失败!!\n");
        return Head;
    }
    p->data = x;
    p->next = Head;
    return p;
}
/*出栈*/
link pop(link Head)
{
    link p;
    p = Head;
    if (p == NULL)
    {
        printf("栈为空!!\n");
    }
    else
    {
        p = p->next;
        free(Head);
    }
    return p;
}

/*取栈顶元素*/
int gettop(link Head)
{
    if (Head == NULL)
    {
        printf("栈为空!!\n");
        return -1;
    }
    else
    {
        return Head->data;
    }
}

/*判断栈是否为空*/
int empty(link Head)
{
    if (Head == NULL)
    {
        return 1;
    }
    else
        return 0;
}

/*显示栈元素*/
void display(link Head)
{
    link p;
    p = Head;
    if (p == NULL)
    {
        printf("栈为空!!\n");
    }
    else
    {
        do
        {
            printf("%d", p->data);
            p = p->next;
        } while (p != NULL);
    }
}
/*释放栈*/
link setnull(link Head)
{
    link p;
    p = Head;
    while (p != NULL)
    {
        p = p->next;
        free(Head);
        Head = p;
    }
    return Head;
}

int main()
{
    int i, x;
    link head1;
    head1 = init();
    int n = 0;
    //link q = (link)malloc(sizeof(Snode));
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head1 = push(head1, x);
    }
    head1 = pop(head1);
    printf("栈顶元素为:%d\n", gettop(head1));
    if (empty(head1) == 1)
    {
        printf("栈为空!!\n");
    }
    else
        printf("栈不为空!!\n");
    display(head1);
    display(setnull(head1));
    system("pause");

    return 0;
}