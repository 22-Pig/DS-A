#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/* 链式队列结点 */
typedef struct LinkNode
{
    ElemType data;         //数据域
    struct LinkNode *next; //指针域
} LinkNode;                //队列结点的类型定义（队列结点的别名）

/* 定义链式队列 */
typedef struct
{
    LinkNode *front, *rear; // 队列的队头指针和队尾指针
} LinkQueue;

/* 初始化队列（不带头结点） */
void InitQueue(LinkQueue &Q)
{
    // 初始化时，fornt、rear都指向NULL
    Q.front = NULL;
    Q.rear = NULL;
}

/* 判断队列是否为空 */
bool IsEmpty(LinkQueue &Q)
{
    if (Q.front == NULL) //队空
        return true;
    else
        return false; //非空
}

/* 入队（尾部插入法） */
void EnQueue(LinkQueue &Q, ElemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode)); //给指针s申请空间
    s->data = x;                                        //将x值赋给s所指向结点
    s->next = NULL;                                     //将s所指向结点指针域置为空（即链尾结点指针域条件）
    if (Q.front == NULL)
    {
        Q.front = s;
        Q.rear = s;
    }
    else
    {
        Q.rear->next = s; //将原队尾结点（Q.rear->）指向s所指向结点
        Q.rear = s;       //使队尾指针指向新队尾结点（s）
    }
}

/* 出队（头部删除法） */
bool DeQueue(LinkQueue &Q, ElemType &x) //出队（将x从队Q中取出）
{
    if (Q.front == NULL)
        return false;
    LinkNode *p = Q.front;
    x = p->data;
    Q.front = p->next;
    if (Q.rear == p)
    {
        Q.front == NULL;
        Q.rear = NULL;
    }
    free(p);
    return true;
}

void testLinkQueue()
{
    LinkQueue Q;  // 声明一个队列
    InitQueue(Q); // 初始化队列
}