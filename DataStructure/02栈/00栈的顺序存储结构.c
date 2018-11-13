#include <stdio.h>
#define StackSize 100
#define MAXSIZE 100
#define ERROR 0
#define OK 1
#define Status int
//ջ�Ľṹ���� ��ͷ��ջ�ף���β��ջ��
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
} SqStack;

//��ջ ����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1) //ջ��
        return ERROR;
    S->top++;            //ջ��ָ������1
    S->data[S->top] = e; //���²���Ԫ��ֵ��ջ���ռ�
    return OK;
}
//��ջ ��ջ��Ԫ�ظ�ֵ��e��ɾ��
//��ջ��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1) //Ϊ��ջ
        return ERROR;
    *e = S->data[S->top]; //��Ҫɾ����ջ��Ԫ�ظ�ֵ��e
    S->top--;             //ջ��ָ���1
    return OK;
}

int main()
{
    return 0;
}