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

/* 初始化队列（带头结点） */
void InitQueue(LinkQueue &Q)
{
    // 初始化时，fornt、rear都指向头结点
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
void EnQueue(LinkQueue &Q, ElemType x)
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

void testLinkQueue()
{
    LinkQueue Q;  // 声明一个队列
    InitQueue(Q); // 初始化队列
}