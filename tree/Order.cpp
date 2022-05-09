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

/* 初始化队列指针 */
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode)); //给队列头尾指针申请空间
    Q.front->next = NULL;                                    //初始化队列为空
}

bool IsEmpty(LinkQueue &Q) //判断队是否为空
{
    if (Q.rear == Q.front) //队空
        return true;
    else
        return false; //非空
}

/* 入队（尾部插入法） */
void EnQueue(LinkQueue &Q, ElemType x) //进队（将x放入队Q中）
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode)); //给指针s申请空间
    s->data = x;                                        //将x值赋给s所指向结点
    s->next = NULL;                                     //将s所指向结点指针域置为空（即链尾结点指针域条件）
    Q.rear->next = s;                                   //将原队尾结点（Q.rear->）指向s所指向结点
    Q.rear = s;                                         //使队尾指针指向新队尾结点（s）
}

/* 出队（头部删除法） */
bool DeQueue(LinkQueue &Q, ElemType &x) //出队（将x从队Q中取出）
{
    if (Q.rear == Q.front)
        return false;            //若队列为空，则报错
    LinkNode *p = Q.front->next; //给指针p申请空间
    x = p->data;                 //将指针p所指向结点值赋给x
    Q.front->next = p->next;     //将指针p所指向结点（p->）的下一个结点赋给头结点（Q.front->）的指针域
    if (Q.rear == p)             //若原队列中只有一个结点，则删除后队尾结针还指向该结点，需重新赋值
        Q.rear = Q.front;        //使队尾指针和队头指针重合，并等于NULL（队列为空）
    free(p);                     //释放申请的p空间
    return true;                 //删除成功
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