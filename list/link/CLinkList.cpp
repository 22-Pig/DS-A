#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/* 初始化一个循环单链表 (带头结点) */
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
    if (L == NULL)                      // 内存不足，分配失败
    {
        return false;
    }
    L->next = L; // 头结点next指向头结点
    return true;
}

/* 判断结点p是否为循环单链表的表尾结点 */
bool isTail(LinkList L, LNode *p)
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

void test()
{
    LinkList L;  // 声明一个指向单链表的指针
    InitList(L); // 初始化一个空表
}