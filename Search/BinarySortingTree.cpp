#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct BSTNode
{
    ElemType key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;
