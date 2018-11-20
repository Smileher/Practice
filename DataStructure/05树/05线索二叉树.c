//lchild     ltag     data     rtag     rchild
//ltag为0时指向该结点的左孩子，为1时指向该结点的前驱
//rtag为0时指向该结点的右孩子，为1时指向该结点的后继
//线索化的过程就是在遍历的过程中修改空指针的过程

//程序代码：输入一个前序序列的二叉树，输出中序遍历的结果
#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
//线索存储标志位
//使用枚举定义一个变量类型，这个变量类型只能定义两种变量
//Link，值是0，表示指向左右孩子的指针
//Thread，值是1，表示指向前驱后继的线索
typedef enum
{
    Link,
    Thread
} PointerTag;

//二叉树线索存储结构
typedef struct BiThrNode
{
    char data;                         //结点数据域
    struct BiThrNode *lchild, *rchild; //左右孩子指针
    PointerTag ltag;                   //左标志
    PointerTag rtag;                   //右标志
} BiThrNode, *BiThrTree;

BiThrTree pre; //全局变量，始终指向刚刚访问过的结点

//创建一课二叉树，约定用户遵照前序遍历的方式输入数据，空位置用#代替
void CreateBiThrTree(BiThrTree *T)
{
    char c;
    scanf("%c", &c);
    if ('#' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;

        CreateBiThrTree(&(*T)->lchild);
        CreateBiThrTree(&(*T)->rchild);
    }
}

//中序遍历进行中序线索化
void InThreading(BiThrTree T)
{
    if (T)
    {
        InThreading(T->lchild); //递归左孩子线索化

        if (!T->lchild) //如果该结点没有左孩子
        {
            T->ltag = Thread; //设置T->ltag为Thread，前驱线索
            T->lchild = pre;  //左孩子指针指向前驱
        }
        if (!pre->rchild) //前驱没有右孩子
        {
            pre->rtag = Thread; //后继线索
            pre->rchild = T;    //前驱右孩子指针指向后继(当前结点T)
        }

        pre = T; //保持pre指向T的前驱

        InThreading(T->rchild); //递归右孩子线索化
    }
}

//在二叉树线索链表上添加一个头结点
//lchild指向二叉树的根结点，rchild指向中序序列的最后一个结点
//令中序序列第一个结点的lchild和最后一个结点rchild都指向头结点
//这样定义的好处就是既可以从第一个结点起顺着后继遍历
//也可以从最后一个结点起顺着前驱进行遍历
void InOrderThreading(BiThrTree *p, BiThrTree T)
{
    *p = (BiThrTree)malloc(sizeof(BiThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if (!T)
    {
        (*p)->lchild = *p;
    }
    else
    {
        (*p)->lchild = T;
        pre = *p;
        InThreading(T);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}
void visit(char c)
{
    printf("%c", c);
}
//中序遍历二叉树，非递归
void InOrderTraverse(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;

    while (p != T)
    {
        while (p->ltag == Link)
        {
            p = p->lchild;
        }
        visit(p->data);

        while (p->rtag == Thread && p->rchild != T)
        {
            p = p->rchild;
            visit(p->data);
        }
        p = p->rchild;
    }
}
int main(void)
{
    BiThrTree P, T = NULL;
    //ABC##D##E#F##
    printf("请输入一个前序遍历的二叉树（用#代替空位置）例如：ABC##D##E#F##：\n");
    CreateBiThrTree(&T);
    InOrderThreading(&P, T);
    printf("中序遍历输出结果为：");
    InOrderTraverse(P);
    printf("\n");
    return 0;
}