//lchild     ltag     data     rtag     rchild
//ltag为0时指向该结点的左孩子，为1时指向该结点的前驱
//rtag为0时指向该结点的右孩子，为1时指向该结点的后继
//线索化的过程就是在遍历的过程中修改空指针的过程
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
//线索存储标志位
//使用枚举定义一个变量类型。这个变量类型只能定义两种变量
//一个是Link，其值是0，另一个是Thread，其值是1
//Link == 0：表示指向左右孩子的指针
//Thread == 1：表示指向前驱后继的线索
typedef enum
{
    Link,
    Thread
} PointerTag;
//二叉树线索存储结构
typedef struct BiThrNode
{
    ElemType data;                     //结点数据域
    struct BiThrNode *lchild, *rchild; //左右孩子指针
    PointerTag ltag;                   //左标志
    PointerTag rtag;                   //右标志
} BiThrNode, *BiThrTree;
//创建一课二叉树，约定用户遵照前序遍历的方式输入数据，空位置用#代替
CreateBiThrTree(BiThrTree *T)
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
//全局变量，始终指向刚刚访问过的结点
BiThrTree pre;
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
        if (!pre->rchild)//前驱没有右孩子
        {
            pre->rtag = Thread;//后继线索
            pre->rchild = T;//前驱右孩子指针指向后继(当前结点T)
        }
        
        pre = T;//保持pre指向T的前驱

        InThreading(T->rchild); //递归右孩子线索化
    }
}
int main(void)
{
    return 0;
}