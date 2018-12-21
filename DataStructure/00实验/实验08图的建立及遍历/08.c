/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *实验八图的建立及遍历
 *****************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define INFINITY 32767
#define MAX_VERTEX_NUM 20

typedef enum
{
    FALSE,
    TRUE
} visited_ch;
typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} graphkind_ch;

typedef struct arccell_ch
{
    int adj;
    int *info;
} arccell_ch, adjmatrix_ch[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
    char vexs[MAX_VERTEX_NUM];
    adjmatrix_ch arcs;
    int vexnum, arcnum;
    graphkind_ch kind;
} mgraph_ch;

typedef struct arcnode_ch
{
    int adjvex;
    struct arcnode_ch *nextarc;
    int *info;
} arcnode_ch;

typedef struct vnode_ch
{
    char data;
    arcnode_ch *firstarc;
} vnode_ch, adjlist_ch[MAX_VERTEX_NUM];

typedef struct
{
    adjlist_ch vertices;
    int vexnum, arcnum;
    graphkind_ch kind;
} algraph_ch;

int locatevex_ch(mgraph_ch *g, char v)
{
    int i, k = 0;
    for (i = 0; i < g->vexnum; i++)
        if (g->vexs[i] == v)
        {
            k = i;
            i = g->vexnum;
        }
    return (k);
}

mgraph_ch *createudg_ch()
{
    mgraph_ch *g;
    char v1, v2;
    int i, j, incinfo;
    g = (mgraph_ch *)malloc(sizeof(mgraph_ch));
    g->kind = UDG;
    printf("请输入图顶点数、边数及该边相关信息:\n");
    scanf("%d %d %d", &g->vexnum, &g->arcnum, &incinfo);
    printf("请输入顶点信息:\n");
    _flushall();
    for (i = 0; i < g->vexnum; ++i)
        scanf("%c", &g->vexs[i]);
    for (i = 0; i < g->vexnum; ++i)
        for (j = 0; j < g->vexnum; ++j)
            g->arcs[i][j].adj = 0;
    printf("输入一条边依附的顶点:\n");
    _flushall();
    scanf("%c%c", &v1, &v2);
    while (v1 != '#' && v2 != '#')
    {
        i = locatevex_ch(g, v1);
        j = locatevex_ch(g, v2);
        g->arcs[i][j].adj = 1;
        if (incinfo)
            g->arcs[i][j].info = &incinfo;
        g->arcs[j][i].adj = g->arcs[i][j].adj;
        g->arcs[j][i].info = g->arcs[i][j].info;
        _flushall();
        scanf("%c%c", &v1, &v2);
    }
    return (g);
}

visited_ch vis[MAX_VERTEX_NUM];

int firstadjvex_ch(mgraph_ch *g, int v)
{
    int i, k = -1;
    for (i = 0; i < g->vexnum; i++)
        if (g->arcs[v][i].adj == 1)
        {
            k = i;
            i = g->vexnum;
        }
    return (k);
}

int nextadjvex_ch(mgraph_ch *g, int v, int w)
{
    int i, k = -1;
    for (i = 0; i < g->vexnum; i++)
        if (g->arcs[v][i].adj == 1 && i > w)
        {
            k = i;
            i = g->vexnum;
        }
    return (k);
}

void dfs_ch(mgraph_ch *g, int v)
{
    int w;
    vis[v] = TRUE;
    printf("%c", g->vexs[v]);
    for (w = firstadjvex_ch(g, v); w >= 0; w = nextadjvex_ch(g, v, w))
        if (!vis[w])
            dfs_ch(g, w);
}

void dfstraverse_ch(mgraph_ch *g)
{
    int v, i;
    char f;
    for (v = 0; v < g->vexnum; v++)
        vis[v] = FALSE;
    printf("输入遍历开始顶点:");
    _flushall();
    scanf("%c", &f);
    i = locatevex_ch(g, f);
    printf("深度遍历结果为:");
    for (v = i; v < g->vexnum; v++)
        if (!vis[v])
            dfs_ch(g, v);
    for (v = 0; v < i; v++)
        if (!vis[v])
            dfs_ch(g, v);
}

int locatevexal_ch(algraph_ch *a, char v)
{
    int i, k = 0;
    for (i = 0; i < a->vexnum; i++)
        if (a->vertices[i].data == v)
        {
            k = i;
            i = a->vexnum;
        }
    return (k);
}

char createlist_ch(algraph_ch *a, arcnode_ch *firstl, char v)
{
    arcnode_ch *nextl;
    if (v != '\n')
    {
        nextl = (arcnode_ch *)malloc(sizeof(arcnode_ch));
        nextl->adjvex = locatevexal_ch(a, v);
        nextl->nextarc = NULL;
        nextl->info = firstl->info;
        firstl->nextarc = nextl;
        scanf("%c", &v);
        v = createlist_ch(a, nextl, v);
    }
    return (v);
}

algraph_ch *createaludg_ch()
{
    algraph_ch *a;
    int i, incinfo;
    char v;
    a = (algraph_ch *)malloc(sizeof(algraph_ch));
    a->kind = UDG;
    printf("请输入图顶点数、边数及该边相关信息:\n");
    scanf("%d %d %d", &a->vexnum, &a->arcnum, &incinfo);
    printf("请输入顶点信息:\n");
    _flushall();
    for (i = 0; i < a->vexnum; ++i)
        scanf("%c", &a->vertices[i].data);
    for (i = 0; i < a->vexnum; ++i)
    {
        printf("输入%c的邻接点:", a->vertices[i].data);
        _flushall();
        scanf("%c", &v);
        a->vertices[i].firstarc = (arcnode_ch *)malloc(sizeof(arcnode_ch));
        a->vertices[i].firstarc->adjvex = locatevexal_ch(a, v);
        a->vertices[i].firstarc->nextarc = NULL;
        if (incinfo)
            a->vertices[i].firstarc->info = &incinfo;
        scanf("%c", &v);
        v = createlist_ch(a, a->vertices[i].firstarc, v);
    }
    return (a);
}

visited_ch vis[MAX_VERTEX_NUM];

void dfsal_ch(algraph_ch *a, arcnode_ch *b, int k)
{
    vis[k] = TRUE;
    printf("%c", a->vertices[k].data);
    while (b)
    {
        k = b->adjvex;
        if (!vis[k])
        {
            b = a->vertices[k].firstarc;
            dfsal_ch(a, b, k);
        }
        else
            b = b->nextarc;
    }
}

void dfstraverseal_ch(algraph_ch *a)
{
    char f;
    int i = 0, k;
    for (i = 0; i < a->vexnum; i++)
        vis[i] = FALSE;
    printf("遍历开始顶点:");
    _flushall();
    scanf("%c", &f);
    k = locatevexal_ch(a, f);
    printf("深度遍历结果:");
    for (i = k; i < a->vexnum; i++)
        if (!vis[k])
            dfsal_ch(a, a->vertices[i].firstarc, i);
    for (i = 0; i < k; i++)
        if (!vis[k])
            dfsal_ch(a, a->vertices[i].firstarc, i);
}

int main(void)
{
    algraph_ch *a;
    mgraph_ch *g;
    char c;
    printf("邻接矩阵(M)|邻接表(A)\n");
    printf("请选择:");
    c = getchar();
    while (c != 'E')
    {
        if (c == 'M')
        {
            g = createudg_ch();
            dfstraverse_ch(g);
        }
        else if (c == 'A')
        {
            a = createaludg_ch();
            dfstraverseal_ch(a);
        }
        printf("\n请再次选择:");
        _flushall();
        c = getchar();
    }
}
