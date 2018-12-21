/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *实验十图的最小生成树算法的实现
 *****************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
    int *vexs;
    int **arcs;
    int vexnum;
} graph_ch;

typedef struct
{
    int adjvex;
    int lowcost;
} markedg_ch;
//定义
graph_ch *initgraph_ch()
{
    int i, j;
    graph_ch *g;
    g = (graph_ch *)malloc(sizeof(graph_ch));
    g->vexnum = 25;
    g->vexs = (int *)malloc(g->vexnum * sizeof(int));
    g->arcs = (int **)malloc(g->vexnum * sizeof(int *));
    for (i = 0; i < g->vexnum; i++)
        g->arcs[i] = (int *)malloc(g->vexnum * sizeof(int));
    for (i = 0; i < g->vexnum; i++)
        for (j = 0; j < g->vexnum; j++)
        {
            g->arcs[i][j] = 0;
        }
    return (g);
}
//创建
void creategraph_ch(graph_ch *g)
{
    int i, j;
    for (i = 0; i < g->vexnum; i++)
        g->vexs[i] = i;
    g->arcs[0][9] = 1892;
    g->arcs[1][3] = 242;
    g->arcs[2][4] = 668;
    g->arcs[2][9] = 1145;
    g->arcs[3][5] = 305;
    g->arcs[4][6] = 137;
    g->arcs[4][11] = 695;
    g->arcs[5][6] = 704;
    g->arcs[5][7] = 397;
    g->arcs[6][12] = 674;
    g->arcs[8][9] = 216;
    g->arcs[9][10] = 676;
    g->arcs[10][11] = 511;
    g->arcs[10][13] = 842;
    g->arcs[11][12] = 349;
    g->arcs[11][14] = 534;
    g->arcs[12][15] = 651;
    g->arcs[13][16] = 110;
    g->arcs[13][17] = 967;
    g->arcs[14][18] = 409;
    g->arcs[15][19] = 825;
    g->arcs[16][17] = 639;
    g->arcs[17][18] = 902;
    g->arcs[17][21] = 607;
    g->arcs[18][19] = 367;
    g->arcs[18][21] = 672;
    g->arcs[18][23] = 675;
    g->arcs[19][20] = 622;
    g->arcs[21][22] = 255;
    g->arcs[23][24] = 140;
    for (i = 0; i < g->vexnum; i++)
        for (j = i; j < g->vexnum; j++)
            if (g->arcs[i][j])
                g->arcs[j][i] = g->arcs[i][j];
}
//输出
void printgraph_ch(graph_ch *g)
{
    int x, y;
    printf("\n城市间连通图为:\n");
    for (x = 0; x < g->vexnum; x++)
        for (y = x; y < g->vexnum; y++)
            if (g->arcs[x][y])
                printf("(%d,%d)距离:%d\t", x, y, g->arcs[x][y]);
}
//遍历
int selectnearvex_ch(markedg_ch *mark, int *flag, int num)
{
    int j;
    int nearestv;
    int lowcost = 32767;
    for (j = 0; j < num; j++)
    {
        if (flag[j] != 1 && mark[j].lowcost < lowcost)
        {
            nearestv = j;
            lowcost = mark[j].lowcost;
        }
    }
    flag[nearestv] = 1;
    return (nearestv);
}

void markothervex_ch(graph_ch *g, markedg_ch *mark, int nearestv, int num, int *flag)
{
    int j;
    for (j = 0; j < num; j++)
    {
        if (g->arcs[nearestv][j] > 0)
        {
            if (flag[j] != 1)
            {
                if (mark[j].lowcost > (mark[nearestv].lowcost + g->arcs[nearestv][j]))
                {
                    mark[j].lowcost = mark[nearestv].lowcost + g->arcs[nearestv][j];
                    mark[j].adjvex = nearestv;
                }
            }
        }
    }
}

void shortestpath_ch(graph_ch *g, markedg_ch *mark, int start)
{
    int i, num;
    int *flag;
    int nearestv;
    num = g->vexnum;
    flag = (int *)malloc((num) * sizeof(int));
    flag[start] = 1;
    for (i = 0; i < g->vexnum; i++)
    {
        mark[i].adjvex = start;
        if (g->arcs[start][i] > 0)
        {
            mark[i].lowcost = g->arcs[start][i];
        }
        else
        {
            mark[i].lowcost = 32767;
        }
    }
    for (i = 1; i < g->vexnum; i++)
    {
        nearestv = selectnearvex_ch(mark, flag, num);
        markothervex_ch(g, mark, nearestv, num, flag);
    }
}

void printshortpath_ch(graph_ch *g, markedg_ch *mark, int start)
{
    int i, j, k, path[25];
    for (i = 0; i < g->vexnum; i++)
    {
        if (i != start)
        {
            printf("从%d到%d最短路径为:%d;  ", start, i, mark[i].lowcost);
            printf("途经代号为:");
            k = 0;
            path[k] = i;
            j = mark[i].adjvex;
            while (j != start)
            {
                path[++k] = j;
                j = mark[j].adjvex;
            }
            printf("%d", start);
            for (j = k; j >= 0; j--)
                printf(",%d", path[j]);
            printf("的城市.\n");
        }
    }
}

int main(void)
{
    int city;
    graph_ch *g;
    markedg_ch *mark;
    g = initgraph_ch();
    creategraph_ch(g);
    printf("代号:城市名称:\n");
    printf("00:乌鲁木齐, 01:哈尔滨, 02:呼和浩特, 03:长春, 04:北京, 05:沈阳, 06:天津\n");
    printf("07:大连, 08:西宁, 09:兰州, 10:西安, 11:郑州, 12:徐州, 13:成都, 14:武汉, 15:上海\n");
    printf("16:昆明, 17:贵阳, 18:株州, 19:南昌, 20:福州, 21:柳州, 22:南宁, 23:广州, 24:深圳.\n");
    printgraph_ch(g);
    mark = (markedg_ch *)malloc(g->vexnum * sizeof(markedg_ch));
    printf("\n输入起始城市代号(0-24);q to quit:");
    scanf("%d", &city);
    while (1)
    {
        if (city >= 0 && city <= 24)
        {
            shortestpath_ch(g, mark, city);
            printshortpath_ch(g, mark, city);
        }
        if (city == 'q')
        {
            exit(0);
        }
        else
        {
            printf("\n输入错误!(0-24):");
        }

        printf("\n再次输入起始城市代号(0-24);q to quit:");
        scanf("%d", &city);
    }
    return 0;
}