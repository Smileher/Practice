//lchild     ltag     data     rtag     rchild
//ltagΪ0ʱָ��ý������ӣ�Ϊ1ʱָ��ý���ǰ��
//rtagΪ0ʱָ��ý����Һ��ӣ�Ϊ1ʱָ��ý��ĺ��
//�������Ĺ��̾����ڱ����Ĺ������޸Ŀ�ָ��Ĺ���
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
//�����洢��־λ
//ʹ��ö�ٶ���һ���������͡������������ֻ�ܶ������ֱ���
//һ����Link����ֵ��0����һ����Thread����ֵ��1
//Link == 0����ʾָ�����Һ��ӵ�ָ��
//Thread == 1����ʾָ��ǰ����̵�����
typedef enum
{
    Link,
    Thread
} PointerTag;
//�����������洢�ṹ
typedef struct BiThrNode
{
    ElemType data;                     //���������
    struct BiThrNode *lchild, *rchild; //���Һ���ָ��
    PointerTag ltag;                   //���־
    PointerTag rtag;                   //�ұ�־
} BiThrNode, *BiThrTree;
//����һ�ζ�������Լ���û�����ǰ������ķ�ʽ�������ݣ���λ����#����
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
//ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
BiThrTree pre;
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
        if (!pre->rchild)//ǰ��û���Һ���
        {
            pre->rtag = Thread;//�������
            pre->rchild = T;//ǰ���Һ���ָ��ָ����(��ǰ���T)
        }
        
        pre = T;//����preָ��T��ǰ��

        InThreading(T->rchild); //�ݹ��Һ���������
    }
}
int main(void)
{
    return 0;
}