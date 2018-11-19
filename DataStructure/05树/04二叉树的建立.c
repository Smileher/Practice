//ǰ�������������
//��������������
//������������Ҹ�
//������������϶��£�������
//��֪ǰ��ͺ������������ȷ��һ�Ŷ�����
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//��λ����#���棬������������ʾ������T

//��ǰ������������н���ֵ(�ַ�)
CreateBiTree1(BiTree *T)
{
    ElemType c;
    scanf("%c", &c);

    if ('#' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        if (!*T)
            return ERROR;
        (*T)->data = c;              //���ɸ����
        CreateBiTree1(&(*T)->lchild); //����������
        CreateBiTree1(&(*T)->rchild); //����������
    }
}

//����������������н���ֵ(�ַ�)
CreateBiTree2(BiTree *T)
{
    ElemType c;
    scanf("%c", &c);

    if ('#' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        if (!*T)
            return ERROR;
        CreateBiTree1(&(*T)->lchild); //����������
        (*T)->data = c;              //���ɸ����
        CreateBiTree1(&(*T)->rchild); //����������
    }
}

//����������������н���ֵ(�ַ�)
CreateBiTree3(BiTree *T)
{
    ElemType c;
    scanf("%c", &c);

    if ('#' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        if (!*T)
            return ERROR;
        CreateBiTree1(&(*T)->lchild); //����������
        CreateBiTree1(&(*T)->rchild); //����������
        (*T)->data = c;              //���ɸ����
    }
}
//���ʶ������ľ������
visit(char c, int level)
{
    printf("\n%c λ�ڵ� %d ��", c, level);
}
//ǰ�����������
void PreOrderTraverse(BiTree T, int level)
{
    if (T == NULL)
        return;
    visit(T->data, level);                  //�ȶԽ����в������ɸ�Ϊֱ�����
    PreOrderTraverse(T->lchild, level + 1); //��ǰ�����������
    PreOrderTraverse(T->rchild, level + 1); //���ǰ�����������
}
int main(void)
{
    int level = 1;
    BiTree T = NULL;
    //AB#D##CE###
    printf("������һ��ǰ������Ķ���������������ȫ����������ʽ��ʾ����#�����λ�ã���\n");
    CreateBiTree1(&T);
    PreOrderTraverse(T, level);
    return 0;
}