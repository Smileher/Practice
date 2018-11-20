//lchild     ltag     data     rtag     rchild
//ltagΪ0ʱָ��ý������ӣ�Ϊ1ʱָ��ý���ǰ��
//rtagΪ0ʱָ��ý����Һ��ӣ�Ϊ1ʱָ��ý��ĺ��
//�������Ĺ��̾����ڱ����Ĺ������޸Ŀ�ָ��Ĺ���

//������룺����һ��ǰ�����еĶ������������������Ľ��
#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
//�����洢��־λ
//ʹ��ö�ٶ���һ���������ͣ������������ֻ�ܶ������ֱ���
//Link��ֵ��0����ʾָ�����Һ��ӵ�ָ��
//Thread��ֵ��1����ʾָ��ǰ����̵�����
typedef enum
{
    Link,
    Thread
} PointerTag;

//�����������洢�ṹ
typedef struct BiThrNode
{
    char data;                         //���������
    struct BiThrNode *lchild, *rchild; //���Һ���ָ��
    PointerTag ltag;                   //���־
    PointerTag rtag;                   //�ұ�־
} BiThrNode, *BiThrTree;

BiThrTree pre; //ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��

//����һ�ζ�������Լ���û�����ǰ������ķ�ʽ�������ݣ���λ����#����
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

//���������������������
void InThreading(BiThrTree T)
{
    if (T)
    {
        InThreading(T->lchild); //�ݹ�����������

        if (!T->lchild) //����ý��û������
        {
            T->ltag = Thread; //����T->ltagΪThread��ǰ������
            T->lchild = pre;  //����ָ��ָ��ǰ��
        }
        if (!pre->rchild) //ǰ��û���Һ���
        {
            pre->rtag = Thread; //�������
            pre->rchild = T;    //ǰ���Һ���ָ��ָ����(��ǰ���T)
        }

        pre = T; //����preָ��T��ǰ��

        InThreading(T->rchild); //�ݹ��Һ���������
    }
}

//�ڶ������������������һ��ͷ���
//lchildָ��������ĸ���㣬rchildָ���������е����һ�����
//���������е�һ������lchild�����һ�����rchild��ָ��ͷ���
//��������ĺô����Ǽȿ��Դӵ�һ�������˳�ź�̱���
//Ҳ���Դ����һ�������˳��ǰ�����б���
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
//����������������ǵݹ�
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
    printf("������һ��ǰ������Ķ���������#�����λ�ã����磺ABC##D##E#F##��\n");
    CreateBiThrTree(&T);
    InOrderThreading(&P, T);
    printf("�������������Ϊ��");
    InOrderTraverse(P);
    printf("\n");
    return 0;
}