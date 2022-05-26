#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100 //顶点数目的最大值
typedef struct
{
    char Vex[MaxVertexNum];               //顶点表(位置)
    int Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
    int vexnum;                           //图的当前顶点数
    int arcnum;                           //图的当前边数
} MGraph;
