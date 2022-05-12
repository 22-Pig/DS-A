#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; //定义ElemType为int类型

typedef struct DNode // 定义双链表结点类型
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

/* 初始化双链表 */
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode)); // 分配一个头结点
    if (L == NULL)                      // 内存不足,分配失败
    {
        return false;
    }
    L->prior = NULL; // 头结点的prior永远指向NULL
    L->next = NULL;  // 头结点之后暂时还没有结点
    return true;
}

bool Empty(DLinkList L)
{
    if (L->next == NULL)
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
    if (p == NULL || s == NULL)
    { // 非法参数
        return false;
    }
    s->next = p->next;   // 将结点*s插入到结点*p之后
    if (p->next != NULL) // 如果p结点有后继结点
    {
        p->next->prior = s;
    }
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
    if (q == NULL)      // p没有后继
    {
        return false;
    }
    p->next = q->next;
    if (q->next != NULL) // q结点不是最后一个结点
    {
        q->next->prior = p;
    }
    free(q); // 释放结点空间
    return true;
}

void DestoryList(DLinkList &L)
{
    /* 循环释放各个数据结点 */
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L);  // 释放头结点
    L = NULL; // 头指针指向NULL
}

void testDLinkList()
{
    /* 初始化双链表 */
    DLinkList L;
    InitDLinkList(L);
}