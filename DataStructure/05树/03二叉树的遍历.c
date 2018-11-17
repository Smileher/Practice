//ǰ�������������
//��������������
//������������Ҹ�
//������������϶��£�������
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;

typedef struct BiNode
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;

//����һ�Ŷ�����,�û���Ҫ����ǰ�������������������ݣ���λ����#����
CreateBiTree(BiTree *T)
{
    char c;
    scanf("%c", &c);

    if ('#' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = c;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
//���ʶ������ľ������
visit(char c, int level)
{
    printf("\n%c λ�ڵ� %d ��", c, level);
}
//ǰ�����������
PreOrderTraverse(BiTree T, int level)
{
    if (T)
    {
        visit(T->data, level);
        PreOrderTraverse(T->lchild, level + 1);
        PreOrderTraverse(T->rchild, level + 1);
    }
}
int main(void)
{
    int level = 1;
    BiTree T = NULL;
    //AB#D##CE###
    printf("������һ��ǰ������Ķ���������������ȫ����������ʽ��ʾ����#�����λ�ã���\n");
    CreateBiTree(&T);
    PreOrderTraverse(T, level);
    return 0;
}