//Adjacency List�ڽӱ�
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
typedef char VertexType; //��������Ӧ���û�����
typedef int EdgeType;    //���ϵ�Ȩֵ����Ӧ���û�����

//�߱�
typedef struct EdgeNode //�߱���
{
    int adjvex; //�ڽӵ��򣬴洢�ö����Ӧ���±�
    //EdgeType weight;       //���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ
    struct EdgeNode *next; //����ָ����һ���ڽӵ�
} EdgeNode;

//�����
typedef struct VertexNode //�������
{
    VertexType data;     //�����򣬴洢������Ϣ
    EdgeNode *firstedge; //�߱�ͷָ��
} VertexNode, AdjList[MAXVEX];

//����ͱ�
typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges; //ͼ�е�ǰ�������ͱ���
} GraphAdjList;

//����ͼ���ڽӱ�����������
//����ͼ���ڽӱ�ṹ
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("�����붥����:\n");
    scanf("%d", &G->numVertexes); //���붥����
    printf("���������:\n");
    scanf("%d", &G->numEdges); //�������
    while (getchar() != '\n')
        continue;
    //���붥����Ϣ�����������һά����涥�㣬��Ӧ��firstedge��ΪNULL
    for (i = 0; i < G->numVertexes; i++)
    {
        printf("�������%d��������ַ�:", i + 1);
        scanf("%c", &G->adjList[i].data); //���붥����Ϣ
        while (getchar() != '\n')
            continue;
        G->adjList[i].firstedge = NULL; //���߱���Ϊ�ձ�
    }
    //����ߵ���Ϣ�������߱���������붥�������Ķ���
    //ÿ�ζ�ȡ���Ϊi,j�Ķ��㣬��ͷ�巨�����ڽ����Ϊi�ĵ����������j��ͬʱ���ڽ����Ϊj�ĵ����������i
    for (k = 0; k < G->numEdges; k++)
    {
        printf("�����(vi,vj)�ϵĶ������(��������0,2��ʾ���Ϊ0��2�Ķ�������):\n");
        scanf("%d,%d", &i, &j); //�����(vi,Vj)�ϵĶ������
        //ͷ�巨�����ڽ����Ϊi�ĵ����������j
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //���ڴ�����ռ䣬���ɱ߱���
        e->adjvex = j;                            //�ڽ����Ϊj
        e->next = G->adjList[i].firstedge;        //��eָ��ָ��ǰ����ָ��Ľ��
        G->adjList[i].firstedge = e;              //����ǰ�����ָ��ָ��e
        //ͷ�巨�����ڽ����Ϊj�ĵ����������i
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //���ڴ�����ռ䣬���ɱ߱���
        e->adjvex = i;                            //�ڽ����Ϊi
        e->next = G->adjList[j].firstedge;        //��eָ��ָ��ǰ����ָ��Ľ��
        G->adjList[j].firstedge = e;              //����ǰ�����ָ��ָ��e
    }
}

//���ͼ
void print(GraphAdjList G)
{
    int i, j, k;
    EdgeNode *e;

    printf("һ����%d�����㣬�ֱ���:", G.numVertexes);
    for (i = 0; i < G.numVertexes; i++)
    {
        printf("%3c", G.adjList[i].data);
    }
    printf("\n");
    for (i = 0; i < G.numVertexes; i++)
    {
        printf("����%c����", G.adjList[i].data);
        e = G.adjList[i].firstedge;
        while (e)
        {
            printf("%c", G.adjList[e->adjvex].data);
            e = e->next;
        }
        printf("\n");
    }
}

int main(void)
{
    GraphAdjList G;
    CreateALGraph(&G);
    print(G);
    return 0;
}
