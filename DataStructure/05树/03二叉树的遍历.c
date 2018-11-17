//前序遍历：根左右
//中序遍历：左根右
//后序遍历：左右根
//层序遍历：从上而下，从左到右
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

//创建一颗二叉树,用户需要按照前序遍历输入二叉树的数据，空位置用#代替
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
//访问二叉树的具体操作
visit(char c, int level)
{
    printf("\n%c 位于第 %d 层", c, level);
}
//前序遍历二叉树
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
    printf("请输入一个前序遍历的二叉树（必须用完全二叉树的形式表示，用#代替空位置）：\n");
    CreateBiTree(&T);
    PreOrderTraverse(T, level);
    return 0;
}