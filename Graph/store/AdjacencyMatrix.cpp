#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100 //顶点数目的最大值
typedef char VertexType; // 顶点的数据类型
typedef int EdgeType;    // 带权图中边上权值的数据类型

typedef struct
{
    VertexType Vex[MaxVertexNum];              //顶点表(位置)
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
    int vexnum;                                //图的当前顶点数
    int arcnum;                                //图的当前边数
} MGraph;
