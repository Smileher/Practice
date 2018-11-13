//˳��ջʵ�ֶ�����תʮ����
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20 //ջ��Ĭ�Ͽռ�
#define STACKINCREMENT 10  //ջ��Ĭ�Ͽռ䲻��ʱ��ÿ�����ӵĿռ�

typedef char ElemType;

//����ջ
typedef struct
{
    ElemType *base; //ջ��
    ElemType *top;  //ջ��
    int stackSize;  //ջ������
} sqStack;

//��ʼ��ջ
void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType)); //Ϊջ�׷���һ�� ElemType���ʹ�С*Ĭ������ �Ŀռ�
    if (!s->base)                                                     //�ж��Ƿ�ɹ�����ռ䡣���ջ��û�з���ɹ����˳�
    {
        exit(0);
    }
    s->top = s->base;               //��ʼ��ʱΪ��ջ����ջ�׸�ֵ��ջ��
    s->stackSize = STACK_INIT_SIZE; //ջ������ΪĬ������
}

//��ջ
void Push(sqStack *s, ElemType e)
{
    if (s->top - s->base >= s->stackSize) //�ж�ջ�Ƿ�����ջ����ַ-ջ�׵�ַ=ջĿǰ�����������ջĿǰ���������ڵ���ջ��Ĭ��������ջ������Ҫ��������
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType)); //��̬�ڴ������realloc(Ҫ�ı��ڴ��С��ָ�������µĴ�С)
        if (!s->base)                                                                               //�ж��Ƿ�ɹ�����ռ䡣���ջ��û�з���ɹ����˳�
        {
            exit(0);
        }
    }
    *(s->top) = e; //����ջ��Ԫ�ظ�ֵ��ջ��
    s->top++;
}

//��ջ
void Pop(sqStack *s, ElemType *e)
{
    if (s->base == s->top) //�ж��Ƿ�Ϊ��ջ
    {
        return;
    }
    *e = *--(s->top); //�Ȱ�ջ��ָ��-1��ȡֵ���ٸ�ֵ��e
}
//��ջĿǰ������
int StackLen(sqStack s)
{
    return (s.top - s.base); //ջ����ַ-ջ�׵�ַ=ջĿǰ������
}

int main(void)
{
    sqStack s;           //����һ��ջs
    ElemType c;          //����һ����ջsԪ����ͬ���͵ı���c
    int len, i, sum = 0; //ջ������len
    InitStack(&s);       //��ʼ��ջ
    printf("�������������������#���ű�ʾ����\n");
    scanf("%c", &c); //����Ԫ��
    while (c != '#')
    {
        Push(&s, c);     //��ջ
        scanf("%c", &c); //����Ԫ��
    }
    getchar(); //��'\n'�Ӽ��̵Ļ��������

    len = StackLen(s); //��ջĿǰ������
    printf("ջ�ĵ�ǰ�����ǣ�%d\n", len);
    for (i = 0; i < len; i++)
    {
        Pop(&s, &c);                      //��ջ
        sum = sum + (c - 48) * pow(2, i); //ÿ�γ�ջ��Ԫ��*2^i��������
    }
    printf("ת��Ϊʮ�������ǣ�%d\n", sum);
    return 0;
}
