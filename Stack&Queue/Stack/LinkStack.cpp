#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义ElemType为int类型

typedef struct StackNode // 定义链栈结点类型
{
    ElemType data;          // 数据域
    struct StackNode *next; // 指针域
} StackNode, *LinkStack;    // 栈类型定义

/* 初始化一个链栈 (不带头结点) */
bool InitLinkStack(LinkStack &S)
{
    S = NULL;
    return true;
}

/* 栈判空 */
bool StackEmpty(LinkStack L)
{
    if (L == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/* 入栈 */
bool Push(LinkStack &S, ElemType e)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return true;
}

/* 出栈 */
bool Pop(LinkStack &S, ElemType &e)
{
    if (S == NULL)
        return false; // 链栈空

    StackNode *p = S;
    e = S->data;
    S = S->next;
    free(p);
    return true;
}

/* 读取栈顶元素 */
bool GetTop(LinkStack S, ElemType &x)
{
    if (S == NULL)
    {
        return false; // 栈空，报错
    }
    StackNode *p = S;
    x = S->data; // x记录栈顶元素
    free(p);
    return true;
}

/* 遍历输出栈 */
void printStack(LinkStack S)
{
    printf("栈顶->");
    StackNode *p = S;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    LinkStack S;      // 声明一个指向链栈的指针
    InitLinkStack(S); // 初始化一个空链栈
    int e, x;
    printf("请输入一个要入栈的元素（-1表示结束）：");
    scanf("%d", &e);
    while (e != -1)
    {
        Push(S, e);
        printf("请输入一个要入栈的元素（-1表示结束）：");
        scanf("%d", &e);
    }
    printStack(S);

    printf("出栈测试：");
    Pop(S, e);
    printStack(S);

    printf("取栈顶元素测试：");
    GetTop(S, x);
    printf("取出的栈顶元素为：%d\n", x);
}