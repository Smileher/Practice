//Adjacency Matrix邻接矩阵
//以下代码为无向网(邻接矩阵，无向图，带权)
//若改为无向图(不带权)，则初始化时 INFINITY 改为0即可
//若改为有向网，则注释 G->arc[j][i] = G->arc[i][j]; 代码即可
#include <stdio.h>
//创建邻接矩阵
typedef char VertexType; //顶点类型应由用户定义
typedef int EdgeType;    //边上的权值类型应由用户定义
#define MAXVEX 100       //最大顶点数，应由用户定义
#define INFINITY 65535   //用65535来代表∞
typedef struct
{
    VertexType vexs[MAXVEX];      //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵，可看作边表
    int numVertexes, numEdges;    //图中当前的顶点数和边数
} MGraph;

//建立无向网
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
        printf("输入边(vi,vj)上的下标i，下标j和权w:（例如:0,1,5）\n");
        scanf("%d,%d,%d", &i, &j, &w); //输入边(vi,vj)的i,j和权w
        while (getchar() != '\n')
            continue;
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j]; //因为是无向图，矩阵对称
    }
}
//输出无向网
void print(MGraph G)
{
    int i, j, k;
    k = 0;
    printf("%5c*******************\n", '\0');
    printf("%6c", '\0');
    for (k = 0; k < G.numVertexes; k++)
    {
        printf("%6c", G.vexs[k]); //输出顶点
    }
    printf("\n");
    for (i = 0; i < G.numVertexes; i++)
    {
        printf("%6c", G.vexs[i]); //输出顶点
        for (j = 0; j < G.numVertexes; j++)
        {
            printf("%6d", G.arc[i][j]); //输出矩阵
        }
        printf("\n");
    }
    printf("%5c*******************\n", '\0');
}
int main(void)
{
    MGraph G;         //定义
    CreateMGraph(&G); //建立
    print(G);         //输出
    return 0;
}

/*
  ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
  │Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
  └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
  │~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │N L│ / │ * │ - │
  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
  │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
  │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
  │ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
  ├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
  │ Ctrl│    │Alt │         Space         │ Alt│    │    │Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←─┘│
  └─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
  Code is far away from bug with the keyboard protecting.
*/