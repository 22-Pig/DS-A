#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct AVLNode
{
    ElemType data; // 数据域
    int balance;   // 平衡因子
    struct AVLNode *lchild, *rchild;
} AVLNode, *AVLTree;
