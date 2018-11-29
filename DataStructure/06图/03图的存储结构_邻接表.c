//Adjacency List�ڽӱ�
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 10
typedef char VertexType; /*��������Ӧ���û�����*/
typedef int EdgeType;    /*���ϵ�Ȩֵ����Ӧ���û�����*/
typedef struct EdgeNode  /*�߱���*/
{
    int adjvex; /*�ڽӵ�ǣ��洢�ö����Ӧ���±�*/

    EdgeType weight; /*���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ*/

    struct EdgeNode *next; /*����ָ����һ���ڽӵ�  */
} EdgeNode;

typedef struct VertexNode /*�������*/
{
    VertexType data;     /*�����򣬴洢������Ϣ*/
    EdgeNode *firstedge; /*�߱�ͷָ��*/
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;

    int numVertexes, numEdges; /*ͼ�е�ǰ�������ͱ���*/

} GraphAdjList;
//����ͼ���ڽӱ�����������
/*����ͼ���ڽӱ�ṹ*/

void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("���붥�����ͱ���:\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges); /*���붥�����ͱ���*/
    for (i = 0; 1 < G->numVertexes; i++)           /*���붥����Ϣ�����������*/
    {
        scanf(&G->adjList[i].data);     /*���붥����Ϣ*/
        G->adjList[i].firstedge = NULL; /*���߱���Ϊ�ձ�*/
    }
    for (k = 0; k < G->numEdges; k++) /*�����߱�*/
    {
        {
            printf("�����(vi,vj)�ϵĶ������:\n");
            scanf("&d,&d", &i, &j);                   /*�����(vIrVj)�ϵĶ������*/
            e = (EdgeNode *)malloc(sizeof(EdgeNode)); /*���ڴ�����ռ䣬*/
                                                      /*���ɱ߱���*/
            e->adjvex = j;                            /*�ڽ����Ϊ��*/

            e->next = G->adjList[i].firstedge;        /*��eָ��ָ��ǰ����ָ��Ľ��*/
            G->adjList[i].firstedge = e;              /*����ǰ�����ָ��ָ��e  */
            e = (EdgeNode *)malloc(sizeof(EdgeNode)); /*���ڴ�����ռ䣬*/
                                                      /*���ɱ߱���*/
            e->adjvex = i;                            /*�ڽ����Ϊi */
            e->next = G->adjList[j].firstedge;        /*��eָ��ָ��ǰ����ָ��Ľ��*/
            G->adjList[j].firstedge = e;              /*����ǰ�����ָ��ָ��e */
        }
    }
}
int main(void)
{
    return 0;
}