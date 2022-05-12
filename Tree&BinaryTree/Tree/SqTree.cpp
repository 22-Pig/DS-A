#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

struct ElemType
{
    int value;
};

/* 树的结点定义 */
typedef struct
{
    ElemType data; // 数据元素
    int parent;    // 双亲位置域
} PTNode;

/* 树的类型定义 */
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE]; // 双亲表示
    int n;                       // 结点数
} PTree;