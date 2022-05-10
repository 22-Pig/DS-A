#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

// typedef int ElemType;

struct ElemType
{
    int value;
};

/* 二叉树的结点（链式存储） */
typedef struct BiTNode
{
    ElemType data;                   // 数据域
    struct BiTNode *lchild, *rchild; // 左、右孩子指针
} BiTNode, *BiTree;

/* 链式队列结点 */
typedef struct LinkNode // 定义链式队列结点
{
    BiTNode data;          //数据域（存指针而不是结点，节省空间）
    struct LinkNode *next; //指针域
} LinkNode;                //队列结点的类型定义（队列结点的别名）

/* 定义链式队列 */
typedef struct
{
    LinkNode *front, *rear; // 队列的队头指针和队尾指针
} LinkQueue;                // 队列的类型定义（队列的别名）

/* 定义一棵空树 */
BiTree T = NULL;

/* 访问根结点 */
void visit(BiTree T)
{
}

/* 先序遍历 */
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);            // 访问根结点
        PreOrder(T->lchild); // 递归遍历左子树
        PreOrder(T->rchild); // 递归遍历右子树
    }
}

/* 中序遍历 */
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild); // 递归遍历左子树
        visit(T);           // 访问根结点
        InOrder(T->rchild); // 递归遍历右子树
    }
}
/* 后序遍历 */
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild); // 递归遍历左子树
        PostOrder(T->rchild); // 递归遍历右子树
        visit(T);             // 访问根结点
    }
}

/* 求树的深度 */
int treeDepth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        // 树的深度=MAX(左子树深度，右子树深度) + 1
        return l > r ? l + 1 : r + 1;
    }
}

/* 初始化队列（带头结点） */
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode)); //给队列头尾指针申请空间
    Q.front->next = NULL;                                    //初始化队列为空
}

/* 判断队列是否为空 */
bool IsEmpty(LinkQueue &Q)
{
    if (Q.rear == Q.front) //队空
        return true;
    else
        return false; //非空
}

/* 入队（尾部插入法） */
void EnQueue(LinkQueue &Q, BiTree x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = *x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

/* 出队（头部删除法） */
bool DeQueue(LinkQueue &Q, BiTree &x)
{
    if (Q.rear == Q.front)
        return false;
    LinkNode *p = Q.front->next;
    *x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}

/* 层序遍历 */
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q); // 初始化辅助队列
    BiTree p;
    EnQueue(Q, T);      // 将根结点入队
    while (!IsEmpty(Q)) // 队列不空则循环
    {
        DeQueue(Q, p); // 队头结点出队
        visit(p);
        if (p->lchild != NULL)
        {
            EnQueue(Q, p->lchild); // 左孩子入队
        }
        if (p->rchild != NULL)
        {
            EnQueue(Q, p->rchild); // 右孩子入队
        }
    }
}