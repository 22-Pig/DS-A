#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100 // 顶点数目的最大值
typedef int InfoType;
typedef char VertexType;

typedef struct ArcNode // 边表结点
{
    int adjvex;           // 该边指向顶点的位置
    struct ArcNode *next; // 指向下一条边的指针
    // InfoType info; 边权值（非必要）
} ArcNode;

typedef struct VNode // 顶点表结点
{
    VertexType data; // 顶点信息
    ArcNode *first;  // 指向第一条依附该顶点的边的指针
} VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 图的顶点数和弧数
} ALGraph;              // ALGraph是以邻接表存储的图类型
