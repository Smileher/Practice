/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *实验九图的最小生成树算法的实现
 *****************/
#include "stdlib.h"
#include "stdio.h"
#include "malloc.h"
#define INFINITY 32767
typedef enum
{
    FALSE,
    TRUE
} panduan_ch;

typedef struct
{
    int fromvex;
    int endvex;
    int weight;
    int tags;
} arclist_ch;
typedef struct
{
    char *vexs;
    int **vexlist;
    arclist_ch *gelist;
    int **arcs;
    int vexnum, edgnum;
} stgraph_ch;

int locatevex_ch(stgraph_ch *st, char v)
{
    int i, k = 0;
    for (i = 0; i < st->vexnum; i++)
        if (st->vexs[i] == v)
        {
            k = i;
            i = st->vexnum;
        }
    return (k);
}

stgraph_ch *creategraph_ch()
{
    stgraph_ch *st;
    int i, j, x, y;
    char a, b;
    if (!(st = (stgraph_ch *)malloc(sizeof(stgraph_ch))))
    {
        printf("出错!");
        exit(0);
    }
    printf("输入图的顶点数和边数:");
    scanf("%d %d", &st->vexnum, &st->edgnum);
    if (!(st->vexs = (char *)malloc(st->vexnum * sizeof(char))))
    {
        printf("出错!");
        exit(0);
    }
    if (!(st->gelist = (arclist_ch *)malloc(st->edgnum * sizeof(arclist_ch))))
    {
        printf("出错!");
        exit(0);
    }
    if (!(st->arcs = (int **)malloc(st->vexnum * sizeof(int *))))
    {
        printf("出错!");
        exit(0);
    }
    if (!(st->vexlist = (int **)malloc(st->vexnum * sizeof(int *))))
    {
        printf("出错!");
        exit(0);
    }
    for (i = 0; i < st->vexnum; i++)
    {
        if (!(st->arcs[i] = (int *)malloc(st->vexnum * sizeof(int))))
        {
            printf("出错!");
            exit(0);
        }
        if (!(st->vexlist[i] = (int *)malloc(st->vexnum * sizeof(int))))
        {
            printf("出错!");
            exit(0);
        }
    }
    printf("输入顶点:");
    _flushall();
    for (i = 0; i < st->vexnum; i++)
        scanf("%c", &st->vexs[i]);
    printf("输入边及权:\n");
    for (i = 0; i < st->edgnum; i++)
    {
        _flushall();
        scanf("%c%c %d", &a, &b, &st->gelist[i].weight);
        x = locatevex_ch(st, a);
        y = locatevex_ch(st, b);
        if (x < y)
            st->gelist[i].fromvex = x, st->gelist[i].endvex = y;
        else
            st->gelist[i].fromvex = y, st->gelist[i].endvex = x;
        st->gelist[i].tags = 0;
    }
    for (i = 0; i < st->vexnum; i++)
        for (j = 0; j < st->vexnum; j++)
            st->arcs[i][j] = 0;
    for (i = 0; i < st->vexnum; i++)
    {
        st->vexlist[i][0] = i;
        for (j = 1; j < st->vexnum; j++)
            st->vexlist[i][j] = -1;
    }
    return (st);
}

int minweight_ch(stgraph_ch *st)
{
    int i, min;
    for (i = 0; i < st->edgnum; i++)
        if (!st->gelist[i].tags)
        {
            min = i;
            i = st->edgnum;
        }
    for (i = 0; i < st->edgnum; i++)
        if (!st->gelist[i].tags && st->gelist[min].weight > st->gelist[i].weight)
            min = i;
    st->gelist[min].tags = 1;
    return (min);
}

panduan_ch samegraph_ch(stgraph_ch *st, int a, int b)
{
    int i, j, k;
    panduan_ch f = FALSE;
    for (i = 0; st->vexlist[a][i] != -1 && !f; i++)
        for (j = 0; st->vexlist[b][j] != -1 && !f; j++)
            if (st->vexlist[a][i] == st->vexlist[b][j])
                f = TRUE;
    if (!f)
    {
        for (i = 0; i < st->vexnum; i++)
        {
            for (j = 0; j < st->vexnum && st->vexlist[i][j] != -1; j++)
            {
                if (st->vexlist[i][j] == a)
                {
                    k = +j;
                    while (st->vexlist[i][k] != -1)
                        k++;
                    st->vexlist[i][k] = b;
                    j = st->vexnum;
                }
                else if (st->vexlist[i][j] == b)
                {
                    k = +j;
                    while (st->vexlist[i][k] != -1)
                        k++;
                    st->vexlist[i][k] = a;
                    j = st->vexnum;
                }
            }
        }
    }
    return (f);
}

stgraph_ch *minspandtree_ch(stgraph_ch *st)
{
    int i, a, b, min;
    for (i = 0; i < st->vexnum - 1; i++)
    {
        min = minweight_ch(st);
        a = st->gelist[min].fromvex;
        b = st->gelist[min].endvex;
        if (samegraph_ch(st, a, b))
            i--;
        else
            st->arcs[a][b] = st->arcs[b][a] = st->gelist[min].weight;
    }
    free(st->vexlist);
    free(st->gelist);
    return (st);
}

void printst(stgraph_ch *st)
{
    int i, j;
    printf("最小生成树:\n");
    for (i = 0; i < st->vexnum; i++)
    {
        for (j = 0; j < st->vexnum; j++)
            printf("%d\t", st->arcs[i][j]);
        printf("\n");
    }
    printf("需要连通的点有:");
    for (i = 0; i < st->vexnum; i++)
        for (j = i; j < st->vexnum; j++)
            if (st->arcs[i][j])
                printf("%c%c  ", st->vexs[i], st->vexs[j]);
}

int main(void)
{
    stgraph_ch *st;
    st = creategraph_ch();
    st = minspandtree_ch(st);
    printst(st);
}
