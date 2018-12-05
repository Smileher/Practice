//DepthFirstSearch������ȱ������ڽӾ����ڽӱ�
#include <stdio.h>
#include <stdlib.h>
typedef char VertexType; //��������Ӧ���û�����
typedef int EdgeType;    //���ϵ�Ȩֵ����Ӧ���û�����
#define TRUE 1
#define FALSE 0
#define MAX 20 //visited[MAX]�������ѷ��ʵĶ���ΪTRUE��δ���ʵĶ���ΪFLASE
//***********************************�ڽӾ���**********************************************
//�ڽӾ��󣺶���
#define MAXVEX 100     //��󶥵�����Ӧ���û�����
#define INFINITY 65535 //��65535�������
typedef struct
{
    VertexType vexs[MAXVEX];      //�����
    EdgeType arc[MAXVEX][MAXVEX]; //�ڽӾ��󣬿ɿ����߱�
    int numVertexes, numEdges;    //ͼ�е�ǰ�Ķ������ͱ���
} MGraph;
//�ڽӾ��󣺴���
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("�����붥����:");
    scanf("%d", &G->numVertexes); //���붥����
    printf("���������:");
    scanf("%d", &G->numEdges); //�������
    while (getchar() != '\n')
        continue;
    for (i = 0; i < G->numVertexes; i++) //���붥����ַ������������(һά����)
    {
        printf("�������%d��������ַ�:", i + 1);
        scanf("%c", &G->vexs[i]);
        while (getchar() != '\n')
            continue;
    }
    for (i = 0; i < G->numVertexes; i++)
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;  //�ڽӾ����ʼ��
    for (k = 0; k < G->numEdges; k++) // ����numEdges���ߣ������ڽӾ���(��ά����)
    {
        printf("�����(vi,vj)�ϵ��±�i���±�j:������:0,1��\n");
        scanf("%d,%d", &i, &j); //�����(vi,vj)��i,j��Ȩw
        while (getchar() != '\n')
            continue;
        G->arc[i][j] = 1;
        G->arc[j][i] = G->arc[i][j]; //��Ϊ������ͼ������Գ�
    }
}
//�ڽӾ���DFS
typedef int Boolean; //Boolean�ǲ������ͣ���ֵ��TURE��FLASE
Boolean visited[MAX];
void DFS_G(MGraph G, int i) //�ڽӾ����������ȵݹ��㷨
{
    int j;
    visited[i] = TRUE;
    printf("%c", G.vexs[i]); //��ӡ���㣬Ҳ������������
    for (j = 0; j < G.numVertexes; j++)
        if (G.arc[i][j] == 1 && !visited[j])
            DFS_G(G, j); //��Ϊ���ʵ��ڽӶ���ݹ����
}
void DFSTraverse_G(MGraph G) //�ڽӾ����������ȱ�������
{
    int i;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE; //��ʼ�����ж���״̬����δ���ʹ�״̬
    for (i = 0; i < G.numVertexes; i++)
        if (!visited[i]) //��δ���ʹ��Ķ������DFS����������ͼ��ֻ��ִ��һ��
            DFS_G(G, i);
}
//***********************************�ڽӱ�***********************************************
//�ڽӱ�����
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

//�ڽӱ�����
void CreateALGraph(GraphAdjList *GL)
{
    int i, j, k;
    EdgeNode *e;
    printf("�����붥����:\n");
    scanf("%d", &GL->numVertexes); //���붥����
    printf("���������:\n");
    scanf("%d", &GL->numEdges); //�������
    while (getchar() != '\n')
        continue;
    //���붥����Ϣ�����������һά����涥�㣬��Ӧ��firstedge��ΪNULL
    for (i = 0; i < GL->numVertexes; i++)
    {
        printf("�������%d��������ַ�:", i + 1);
        scanf("%c", &GL->adjList[i].data); //���붥����Ϣ
        while (getchar() != '\n')
            continue;
        GL->adjList[i].firstedge = NULL; //���߱���Ϊ�ձ�
    }
    //����ߵ���Ϣ�������߱���������붥�������Ķ���
    //ÿ�ζ�ȡ���Ϊi,j�Ķ��㣬��ͷ�巨�����ڽ����Ϊi�ĵ����������j��ͬʱ���ڽ����Ϊj�ĵ����������i
    for (k = 0; k < GL->numEdges; k++)
    {
        printf("�����(vi,vj)�ϵĶ������(��������0,2��ʾ���Ϊ0��2�Ķ�������):\n");
        scanf("%d,%d", &i, &j); //�����(vi,Vj)�ϵĶ������
        //ͷ�巨�����ڽ����Ϊi�ĵ����������j
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //���ڴ�����ռ䣬���ɱ߱���
        e->adjvex = j;                            //�ڽ����Ϊj
        e->next = GL->adjList[i].firstedge;       //��eָ��ָ��ǰ����ָ��Ľ��
        GL->adjList[i].firstedge = e;             //����ǰ�����ָ��ָ��e
        //ͷ�巨�����ڽ����Ϊj�ĵ����������i
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //���ڴ�����ռ䣬���ɱ߱���
        e->adjvex = i;                            //�ڽ����Ϊi
        e->next = GL->adjList[j].firstedge;       //��eָ��ָ��ǰ����ָ��Ľ��
        GL->adjList[j].firstedge = e;             //����ǰ�����ָ��ָ��e
    }
}

//�ڽӱ�DFS
void DFS_GL(GraphAdjList GL, int i) //�ڽӱ��������ȵݹ��㷨
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c", GL.adjList[i].data); //��ӡ���㣬Ҳ������������
    p = GL.adjList[i].firstedge;
    while (p)
    {
        DFS_GL(GL, p->adjvex);
        p = p->next;
    }
}
void DFSTraverse_GL(GraphAdjList GL) //�ڽӱ��������ȱ�������
{
    int i;
    for (i = 0; i < GL.numVertexes; i++)
        visited[i] = FALSE; //��ʼ�����ж���״̬����δ���ʹ�״̬
    for (i = 0; i < GL.numVertexes; i++)
        if (!visited[i]) //��δ���ʹ��Ķ������DFS����������ͼ��ֻ��ִ��һ��
            DFS_GL(GL, i);
}

int main(void)
{
    char ch;
    printf("�ڽӾ�����ڽӱ��������ȱ���\n");
    printf("�ڽӾ�������A���ڽӱ�����B\n");
    scanf("%c", &ch);
    if (ch == 'A')
    {
        MGraph G;         //����
        CreateMGraph(&G); //����
        printf("������ȱ���������ڽӾ�����Ϊ��");
        DFSTraverse_G(G); //����
    }
    if (ch == 'B')
    {
        GraphAdjList GL;    //����
        CreateALGraph(&GL); //����
        printf("������ȱ���������ڽӱ���Ϊ��");
        DFSTraverse_GL(GL); //����
    }
    else
    {
        printf("�������!");
    }
}