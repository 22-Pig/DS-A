#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义ElemType为int类型

typedef struct LNode // 定义单链表结点类型
{
    ElemType data;      // 每个结点存放一个数据元素
    struct LNode *next; // 指针指向下一个结点
} LNode, *LinkList;

/* 初始化一个单链表 (不带头结点) */
bool InitList(LinkList &L)
{
    L = NULL;
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

/* 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点 */
void Del_x_1(LinkList &L, ElemType x)
{
    LNode *p;
    if (L == NULL)
        return;
    if (L->data == x)
    {
        p = L;
        L = L->next;
        free(p);
        Del_x_1(L, x);
    }
    else
        Del_x_1(L->next, x);
}
/* L为带头的单链表，本算法删除L中所有值为x的结点 */
void Del_x_2(LinkList &L, ElemType x)
{
    LNode *p = L->next, *pre = L, *q; //置 p 和 pre 的初始值
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p; // q指向该结点
            p = p->next;
            pre->next = p; //删除*q 结点
            free(q);       //释放 *q结点的空间
        }
        else
        { //否则，pre和p同步后移
            pre = p;
            p = p->next;
        }
    }
}

/* 建立新链表的方式，中间会断开 */
void Del_x_2_2(LinkList &L, ElemType x)
{
    LNode *p = L->next, *r = L, *q; // r指向尾结点，其初始值为头结点
    while (p != NULL)
    {
        if (p->data != x)
        { //*p结点值不为x时将其链接到L尾部
            r->next = p;
            r = p;
            p = p->next; //继续扫描
        }
        else
        { //*p结点值为x时将其释放
            q = p;
            p = p->next; //继续扫描
            free(q);     //释放空间
        }
    }               // while
    r->next = NULL; //插入结束后置尾结点指针为NULL
}

void test()
{
    LinkList L;  // 声明一个指向单链表的指针
    InitList(L); // 初始化一个空表
}