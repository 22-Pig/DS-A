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

/* 在先序线索二叉树中找到结点p的后继结点 */
ThreadNode *Nextnode(ThreadNode *p)
{
    if (p->rtag == 0)
    {
        if (p->lchild)
        {
            return p->lchild;
        }
        else
        {
            return p->rchild;
        }
    }
    else
    {
        return p->rchild; // rtag==1直接返回后继线索
    }
}
