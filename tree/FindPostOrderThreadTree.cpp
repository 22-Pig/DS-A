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

/* 在后序线索二叉树中找到结点p的前驱结点 */
ThreadNode *Prenode(ThreadNode *p)
{
    if (p->ltag == 0)
    {
        if (p->rchild)
        {
            return p->rchild;
        }
        else
        {
            return p->lchild;
        }
    }
    else
    {
        return p->lchild; // ltag==1直接返回后继线索
    }
}
