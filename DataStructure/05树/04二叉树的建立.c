//前序遍历：根左右
//中序遍历：左根右
//后序遍历：左右根
//层序遍历：从上而下，从左到右
//已知前序和后序遍历，不能确定一颗二叉树
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

//空位置用#代替，构造二叉链表表示二叉树T

//按前序输入二叉树中结点的值(字符)
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
        (*T)->data = c;              //生成根结点
        CreateBiTree1(&(*T)->lchild); //构造左子树
        CreateBiTree1(&(*T)->rchild); //构造右子树
    }
}

//按中序输入二叉树中结点的值(字符)
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
        CreateBiTree1(&(*T)->lchild); //构造左子树
        (*T)->data = c;              //生成根结点
        CreateBiTree1(&(*T)->rchild); //构造右子树
    }
}

//按中序输入二叉树中结点的值(字符)
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
        CreateBiTree1(&(*T)->lchild); //构造左子树
        CreateBiTree1(&(*T)->rchild); //构造右子树
        (*T)->data = c;              //生成根结点
    }
}
//访问二叉树的具体操作
visit(char c, int level)
{
    printf("\n%c 位于第 %d 层", c, level);
}
//前序遍历二叉树
void PreOrderTraverse(BiTree T, int level)
{
    if (T == NULL)
        return;
    visit(T->data, level);                  //先对结点进行操作，可改为直接输出
    PreOrderTraverse(T->lchild, level + 1); //再前序遍历左子树
    PreOrderTraverse(T->rchild, level + 1); //最后前序遍历右子树
}
int main(void)
{
    int level = 1;
    BiTree T = NULL;
    //AB#D##CE###
    printf("请输入一个前序遍历的二叉树（必须用完全二叉树的形式表示，用#代替空位置）：\n");
    CreateBiTree1(&T);
    PreOrderTraverse(T, level);
    return 0;
}