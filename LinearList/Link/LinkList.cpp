#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义ElemType为int类型

typedef struct LNode // 定义单链表结点类型
{
    ElemType data;      // 每个结点存放一个数据元素
    struct LNode *next; // 指针指向下一个结点
} LNode, *LinkList;

/* 初始化一个单链表 (带头结点) */
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
    if (L == NULL)                      // 内存不足，分配失败
    {
        return false;
    }
    L->next = NULL; // 头结点之后暂时还没有结点
    return true;
}

/* 判断单链表是否为空 (带头结点) */
bool Empty(LinkList L)
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

/* 时间复杂度O(n) 时间代价低 */
/* 按位序插入 (带头结点) */
bool ListInsert(LinkList &L, ElemType i, ElemType e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *p = GetElem(L, i - 1); // 找到第i-1个结点
    return InsertNextNode(p, e);
}

/* 按位序插入 (不带头结点) */
bool ListInsertWithoutHead(LinkList &L, ElemType i, ElemType e)
{
    if (i < 1)
    {
        return false;
    }
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s; // 将头指针指向新结点
        return true;
    }

    LNode *p;  // 指针p指向当前扫描到的结点
    int j = 1; // 当前p指向的是第几个结点
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL) // i值不合法
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; // 将结点s连到p之后
    return true; // 插入成功
}

/* 指定结点的后插 */
bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) // 内存分配失败
    {
        return false;
    }
    s->data = e; // 用结点s保存数据元素e
    s->next = p->next;
    p->next = s; // 将结点s连到p之后
    return true; // 插入成功
}

/* 指定结点的前插 */
bool InsertPriorNode(LNode *p, LNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }

    s->next = p->next;
    p->next = s;             // 将新结点s连到p之后
    ElemType temp = p->data; // 交换数据域部分
    p->data = s->data;
    s->data = temp;
    return true; // 插入成功
}

/* 时间复杂度O(n) 时间代价低 */
/* 按位序删除 (带头结点) */
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *p = GetElem(L, i - 1); // 找到第i-1个结点
    if (p == NULL)                // i值不合法
    {
        return false;
    }
    if (p->next == NULL)
    {
        return false;
    }
    LNode *q = p->next; // 令q指向被删除结点
    e = q->data;        // 用e返回被删除元素的值
    p->next = q->next;  // 将*结点从链中"断开"
    free(p);            // 释放结点的存储空间
    return true;        // 删除成功
}

/* 删除指定结点p (存在删除尾部结点的bug) */
bool DeleteNode(LNode *p)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *q = p->next;      // 令q指向*p的后继结点
    p->data = p->next->data; // 和后继结点交换数据域
    p->next = q->next;       // 将*q结点从链中"断开"
    free(q);                 // 释放后继结点的存储空间
    return true;
}

/* 按位查找(带头结点) 时间复杂度O(n) */
LNode *GetElem(LinkList L, int i)
{
    int j = 1;          // 当前p指向的是第几个结点
    LNode *p = L->next; // 指针p指向当前扫描到的结点
    if (i == 0)
    {
        return L;
    }
    if (i < 1)
    {
        return NULL;
    }
    while (p != NULL && j < i) // 循环找到第i个结点
    {
        p = p->next;
        j++;
    }
    return p;
}

/* 按值查找(带头结点) */
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next; // 指针p指向当前扫描到的结点
    // 从第i个结点开始查找数据域为e的结点
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p; // 找到后返回该结点指针,否则返回NULL
}

/* 求表的长度 */
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

/* 尾插法建立单链表 */
LinkList List_TailInsert(LinkList &L)
{
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode)); // 建立头结点
    LNode *s, *r = L;                    // r为表尾指针
    scanf("%d", &x);                     // 输入结点的值
    while (x != -1)                      // 输入-1表示结束
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s; // r指向新的表尾结点
        scanf("%d", &x);
    }
    r->next = NULL; // 尾结点指针置空
    return L;
}

/* 头插法建立单链表 */
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode)); // 建立头结点
    L->next = NULL;                      // 初始为空链表
    scanf("%d", &x);                     // 输入结点的值
    while (x != -1)                      // 输入-1表示结束
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s; // 将新结点插入表中,L为头指针
        scanf("%d", &x);
    }
    return L;
}

void test()
{
    LinkList L;  // 声明一个指向单链表的指针
    InitList(L); // 初始化一个空表
}