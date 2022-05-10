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

void visit(ThreadNode *p)
{
}

/* 找到以p为根的子树中，第一个被中序遍历的结点 */
ThreadNode *Firstnode(ThreadNode *p)
{
    // 循环找到最左下结点（不一定是叶结点）
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}

/* 在中序线索二叉树中找到结点p的后继结点 */
ThreadNode *Nextnode(ThreadNode *p)
{
    // 右子树中最左下结点
    if (p->rtag == 0)
    {
        return Firstnode(p->rchild);
    }
    else
    {
        return p->rchild; // rtag==1直接返回后继线索
    }
}

/* 对中序线索二叉树进行中序遍历（利用线索实现的非递归算法） */
void Inorder(ThreadNode *T)
{
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
    {
        visit(p);
    }
}

/* 找到以p为根的子树中，最后一个被中序遍历的结点 */
ThreadNode *Lastnode(ThreadNode *p)
{
    // 循环找到最右下结点（不一定是叶结点）
    while (p->rtag == 0)
    {
        p = p->rchild;
    }
    return p;
}

/* 在中序线索二叉树中找到结点p的前驱结点 */
ThreadNode *Prenode(ThreadNode *p)
{
    // 左子树中最右下结点
    if (p->ltag == 0)
    {
        return Lastnode(p->lchild);
    }
    else
    {
        return p->lchild; // ltag==1直接返回后继线索
    }
}

/* 对中序线索二叉树进行逆向中序遍历（利用线索实现的非递归算法） */
void RevInorder(ThreadNode *T)
{
    for (ThreadNode *p = Lastnode(T); p != NULL; p = Prenode(p))
    {
        visit(p);
    }
}