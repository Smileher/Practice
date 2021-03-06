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

//创建一颗二叉树,用户需要按照前序遍历输入二叉树的数据，空位置用#代替
CreateBiTree(BiTree *T)
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
        CreateBiTree(&(*T)->lchild); //构造左子树
        CreateBiTree(&(*T)->rchild); //构造右子树
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
//中序遍历二叉树
void InOrderTreaverse(BiTree T, int level)
{
    if (T = NULL)
        return;
    InOrderTreaverse(T->lchild, level + 1); //先中序遍历左子树
    visit(T->data, level);                  //再对结点进行操作，可改为直接输出
    InOrderTreaverse(T->rchild, level + 1); //最后中序遍历右子树
}
//后序遍历二叉树
void PostOrderTreaverse(BiTree T, int level)
{
    if (T = NULL)
        return;
    PostOrderTreaverse(T->lchild, level + 1); //先后序遍历左子树
    PostOrderTreaverse(T->rchild, level + 1); //再后序遍历右子树
    visit(T->data, level);                    //最后对结点进行操作，可改为直接输出
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