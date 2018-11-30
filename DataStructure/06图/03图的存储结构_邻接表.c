//Adjacency List邻接表
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
typedef char VertexType; //顶点类型应由用户定义
typedef int EdgeType;    //边上的权值类型应由用户定义

//边表
typedef struct EdgeNode //边表结点
{
    int adjvex; //邻接点域，存储该顶点对应的下标
    //EdgeType weight;       //用于存储权值，对于非网图可以不需要
    struct EdgeNode *next; //链域，指向下一个邻接点
} EdgeNode;

//顶点表
typedef struct VertexNode //顶点表结点
{
    VertexType data;     //顶点域，存储顶点信息
    EdgeNode *firstedge; //边表头指针
} VertexNode, AdjList[MAXVEX];

//顶点和边
typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges; //图中当前顶点数和边数
} GraphAdjList;

//无向图的邻接表创建代码如下
//建立图的邻接表结构
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("请输入顶点数:\n");
    scanf("%d", &G->numVertexes); //输入顶点数
    printf("请输入边数:\n");
    scanf("%d", &G->numEdges); //输入边数
    while (getchar() != '\n')
        continue;
    //输入顶点信息，建立顶点表，一维数组存顶点，对应的firstedge置为NULL
    for (i = 0; i < G->numVertexes; i++)
    {
        printf("请输入第%d个顶点的字符:", i + 1);
        scanf("%c", &G->adjList[i].data); //输入顶点信息
        while (getchar() != '\n')
            continue;
        G->adjList[i].firstedge = NULL; //将边表置为空表
    }
    //输入边的信息，建立边表，单链表存与顶点相连的顶点
    //每次读取序号为i,j的顶点，用头插法，在邻接序号为i的单链表里插入j，同时在邻接序号为j的单链表里插入i
    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi,vj)上的顶点序号(例如输入0,2表示编号为0和2的顶点相连):\n");
        scanf("%d,%d", &i, &j); //输入边(vi,Vj)上的顶点序号
        //头插法，在邻接序号为i的单链表里插入j
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //向内存申请空间，生成边表结点
        e->adjvex = j;                            //邻接序号为j
        e->next = G->adjList[i].firstedge;        //将e指针指向当前顶点指向的结点
        G->adjList[i].firstedge = e;              //将当前顶点的指针指向e
        //头插法，在邻接序号为j的单链表里插入i
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //向内存申请空间，生成边表结点
        e->adjvex = i;                            //邻接序号为i
        e->next = G->adjList[j].firstedge;        //将e指针指向当前顶点指向的结点
        G->adjList[j].firstedge = e;              //将当前顶点的指针指向e
    }
}

//输出图
void print(GraphAdjList G)
{
    int i, j, k;
    EdgeNode *e;

    printf("一共有%d个顶点，分别是:", G.numVertexes);
    for (i = 0; i < G.numVertexes; i++)
    {
        printf("%3c", G.adjList[i].data);
    }
    printf("\n");
    for (i = 0; i < G.numVertexes; i++)
    {
        printf("顶点%c连接", G.adjList[i].data);
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
