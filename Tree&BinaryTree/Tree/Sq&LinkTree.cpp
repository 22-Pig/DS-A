#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

struct ElemType
{
    int value;
};

struct CTNode
{
    int child;           // 孩子结点在数组中的位置
    struct CTNode *next; // 下一个孩子
};

typedef struct
{
    ElemType data;
    struct CTNode *firstChild; // 第一个孩子
} CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r; // 结点数和根的位置
} CTree;