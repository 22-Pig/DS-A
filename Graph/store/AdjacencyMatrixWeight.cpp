#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100     //顶点数目的最大值
#define INFINITY 最大的int值 //宏定义常量无穷

typedef int EdgeType; // 定义EdgeType为int类型

//注:有时候会把带权图中自己指向自己的回路的权值设为0
typedef struct
{
    char Vex[MaxVertexNum];                    //顶点
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; //边的权
    int vexnum;                                //顶点数
    int arcnum;                                //弧数
} MGraph;
