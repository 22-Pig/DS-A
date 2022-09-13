#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10 // 定义栈中元素的最大个数
typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize]; // 静态数组存放栈中元素
    int top;                // 栈顶指针
} SqStack;

/* 初始化栈 */
void InitStack(SqStack &S)
{
    S.top = -1; // 初始化栈顶指针
}

bool StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 新元素入栈 */
bool Push(SqStack &S, ElemType x)
{
    if (S.top == MaxSize - 1)
    {
        return false; // 栈满，报错
    }
    // S.data[++S.top] = x;
    S.top = S.top + 1; // 指针先加1
    S.data[S.top] = x; // 新元素入栈
    return true;
}

/* 出栈操作 */
bool Pop(SqStack &S, ElemType &x)
{
    if (S.top == -1)
    {
        return false; // 栈空，报错
    }
    // x = S.data[S.top--];
    x = S.data[S.top]; // 栈顶元素先出栈
    S.top = S.top - 1; // 指针减一
    return true;
}

/* 读取栈顶元素 */
bool GetTop(SqStack S, ElemType &x)
{
    if (S.top == -1)
    {
        return false; // 栈空，报错
    }
    x = S.data[S.top]; // x记录栈顶元素
    return true;
}

void test()
{
    SqStack S; // 声明一个顺序栈(分配空间)
    InitStack(S);
}