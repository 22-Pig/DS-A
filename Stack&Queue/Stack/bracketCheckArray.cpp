#include <stdio.h>
#include <string.h>
#define MaxSize 100

typedef struct
{
    char data[MaxSize];
    int top;
} SqStack;

bool InitStack(SqStack &S)
{
    S.top = -1; // 初始化栈顶指针
}

bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &S, char x)
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

bool Pop(SqStack &S, char &x)
{
    if (S.top == -1)
        return false;

    x = S.data[S.top--];
    return true;
}

bool bracketCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(S, str[i]); //扫描到左括号，入栈
        }
        else
        {
            if (StackEmpty(S)) //扫描到右括号且栈空
                return false;  //匹配失败

            char topElem;
            Pop(S, topElem); //栈顶元素出栈
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S); //检索完全部括号后，栈空说明匹配成功
}

int main()
{
    SqStack S; // 声明一个顺序栈(分配空间)
    InitStack(S);
}

/*
[([][])]{}
[([][]{)]{}
[([][])]{}}
*/