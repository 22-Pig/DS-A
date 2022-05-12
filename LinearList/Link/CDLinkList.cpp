#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; //定义ElemType为int类型

typedef struct DNode // 定义双链表结点类型
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

/* 初始化循环双链表 */
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode)); // 分配一个头结点
    if (L == NULL)                      // 内存不足,分配失败
    {
        return false;
    }
    L->prior = L; // 头结点的prior永远指向NULL
    L->next = L;  // 头结点之后暂时还没有结点
    return true;
}

bool Empty(DLinkList L)
{
    if (L->next == L)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL) // 非法参数
    {
        return false;
    }
    s->next = p->next; // 将结点*s插入到结点*p之后
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
    {
        return false;
    }
    DNode *q = p->next; // 找到p的后继结点q
    if (q == NULL)
    {
        return false;
    }
    p->next = q->next;
    q->next->prior = p;
    free(q); // 释放结点空间
    return true;
}

/* 判断结点p是否为循环双链表的表尾结点 */
bool isTail(DLinkList L, DNode *p)
{
    if (p->next == L)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void testDLinkList()
{
    /* 初始化循环双链表 */
    DLinkList L;
    InitDLinkList(L);
}