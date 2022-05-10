#include <stdio.h>
#include <stdlib.h>

// typedef int ElemType;

struct ElemType
{
    int value;
};

/* 线索二叉树的结点（链式存储） */
typedef struct ThreadNode
{
    ElemType data;                      // 数据域
    struct ThreadNode *lchild, *rchild; // 左、右孩子指针
    // 0表示指针指向孩子，1表示指针是线索
    int ltag, rtag; // 左、右线索标志
} ThreadNode, *ThreadTree;
