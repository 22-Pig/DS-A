#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

struct ElemType
{
    int value;
};

typedef struct BiTNode
{
    ElemType data;                   // 数据域
    struct BiTNode *lchild, *rchild; // 左、右孩子指针
} BiTNode, *BiTree;

/* 定义一棵空树 */
BiTree root = NULL;

/* 插入根结点 */
bool InsertRoot()
{
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;
}

/* 插入新结点 */
bool InsertSubtree()
{
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p;
}