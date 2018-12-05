//DepthFirstSearch深度优先遍历（邻接矩阵，邻接表）
#include <stdio.h>
#include <stdlib.h>
typedef char VertexType; //顶点类型应由用户定义
typedef int EdgeType;    //边上的权值类型应由用户定义
#define TRUE 1
#define FALSE 0
#define MAX 20 //visited[MAX]数组中已访问的顶点为TRUE，未访问的顶点为FLASE
//***********************************邻接矩阵**********************************************
//邻接矩阵：定义
#define MAXVEX 100     //最大顶点数，应由用户定义
#define INFINITY 65535 //用65535来代表∞
typedef struct
{
    VertexType vexs[MAXVEX];      //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵，可看作边表
    int numVertexes, numEdges;    //图中当前的顶点数和边数
} MGraph;
//邻接矩阵：创建
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("请输入顶点数:");
    scanf("%d", &G->numVertexes); //输入顶点数
    printf("请输入边数:");
    scanf("%d", &G->numEdges); //输入边数
    while (getchar() != '\n')
        continue;
    for (i = 0; i < G->numVertexes; i++) //输入顶点的字符，建立顶点表(一维数组)
    {
        printf("请输入第%d个顶点的字符:", i + 1);
        scanf("%c", &G->vexs[i]);
        while (getchar() != '\n')
            continue;
    }
    for (i = 0; i < G->numVertexes; i++)
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;  //邻接矩阵初始化
    for (k = 0; k < G->numEdges; k++) // 读入numEdges条边，建立邻接矩阵(二维数组)
    {
        printf("输入边(vi,vj)上的下标i，下标j:（例如:0,1）\n");
        scanf("%d,%d", &i, &j); //输入边(vi,vj)的i,j和权w
        while (getchar() != '\n')
            continue;
        G->arc[i][j] = 1;
        G->arc[j][i] = G->arc[i][j]; //因为是无向图，矩阵对称
    }
}
//邻接矩阵：DFS
typedef int Boolean; //Boolean是布尔类型，其值是TURE或FLASE
Boolean visited[MAX];
void DFS_G(MGraph G, int i) //邻接矩阵的深度优先递归算法
{
    int j;
    visited[i] = TRUE;
    printf("%c", G.vexs[i]); //打印顶点，也可以其它操作
    for (j = 0; j < G.numVertexes; j++)
        if (G.arc[i][j] == 1 && !visited[j])
            DFS_G(G, j); //对为访问的邻接顶点递归调用
}
void DFSTraverse_G(MGraph G) //邻接矩阵的深度优先遍历操作
{
    int i;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE; //初始化所有顶点状态都是未访问过状态
    for (i = 0; i < G.numVertexes; i++)
        if (!visited[i]) //对未访问过的顶点调用DFS，若是连接图，只会执行一次
            DFS_G(G, i);
}
//***********************************邻接表***********************************************
//邻接表：定义
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

//邻接表：创建
void CreateALGraph(GraphAdjList *GL)
{
    int i, j, k;
    EdgeNode *e;
    printf("请输入顶点数:\n");
    scanf("%d", &GL->numVertexes); //输入顶点数
    printf("请输入边数:\n");
    scanf("%d", &GL->numEdges); //输入边数
    while (getchar() != '\n')
        continue;
    //输入顶点信息，建立顶点表，一维数组存顶点，对应的firstedge置为NULL
    for (i = 0; i < GL->numVertexes; i++)
    {
        printf("请输入第%d个顶点的字符:", i + 1);
        scanf("%c", &GL->adjList[i].data); //输入顶点信息
        while (getchar() != '\n')
            continue;
        GL->adjList[i].firstedge = NULL; //将边表置为空表
    }
    //输入边的信息，建立边表，单链表存与顶点相连的顶点
    //每次读取序号为i,j的顶点，用头插法，在邻接序号为i的单链表里插入j，同时在邻接序号为j的单链表里插入i
    for (k = 0; k < GL->numEdges; k++)
    {
        printf("输入边(vi,vj)上的顶点序号(例如输入0,2表示编号为0和2的顶点相连):\n");
        scanf("%d,%d", &i, &j); //输入边(vi,Vj)上的顶点序号
        //头插法，在邻接序号为i的单链表里插入j
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //向内存申请空间，生成边表结点
        e->adjvex = j;                            //邻接序号为j
        e->next = GL->adjList[i].firstedge;       //将e指针指向当前顶点指向的结点
        GL->adjList[i].firstedge = e;             //将当前顶点的指针指向e
        //头插法，在邻接序号为j的单链表里插入i
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //向内存申请空间，生成边表结点
        e->adjvex = i;                            //邻接序号为i
        e->next = GL->adjList[j].firstedge;       //将e指针指向当前顶点指向的结点
        GL->adjList[j].firstedge = e;             //将当前顶点的指针指向e
    }
}

//邻接表：DFS
void DFS_GL(GraphAdjList GL, int i) //邻接表的深度优先递归算法
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c", GL.adjList[i].data); //打印顶点，也可以其它操作
    p = GL.adjList[i].firstedge;
    while (p)
    {
        DFS_GL(GL, p->adjvex);
        p = p->next;
    }
}
void DFSTraverse_GL(GraphAdjList GL) //邻接表的深度优先遍历操作
{
    int i;
    for (i = 0; i < GL.numVertexes; i++)
        visited[i] = FALSE; //初始化所有顶点状态都是未访问过状态
    for (i = 0; i < GL.numVertexes; i++)
        if (!visited[i]) //对未访问过的顶点调用DFS，若是连接图，只会执行一次
            DFS_GL(GL, i);
}

int main(void)
{
    char ch;
    printf("邻接矩阵和邻接表的深度优先遍历\n");
    printf("邻接矩阵输入A，邻接表输入B\n");
    scanf("%c", &ch);
    if (ch == 'A')
    {
        MGraph G;         //定义
        CreateMGraph(&G); //建立
        printf("深度优先遍历输入的邻接矩阵结果为：");
        DFSTraverse_G(G); //遍历
    }
    if (ch == 'B')
    {
        GraphAdjList GL;    //定义
        CreateALGraph(&GL); //建立
        printf("深度优先遍历输入的邻接表结果为：");
        DFSTraverse_GL(GL); //遍历
    }
    else
    {
        printf("输入错误!");
    }
}