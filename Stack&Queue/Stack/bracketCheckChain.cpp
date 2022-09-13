#include <iostream>
#include <cstring>
using namespace std;
typedef struct LinkNode
{
    char data;             //数据域
    struct LinkNode *next; //指针域
} * LinkStack;             //栈类型定义

bool InitLinkStack(LinkStack &S)
{
    S = (LinkStack)malloc(sizeof(LinkNode)); //分配一个头结点
    if (S == nullptr)                        //内存不足，分配失败
        return false;
    S->next = nullptr; //头结点之后暂时还没有结点
    return true;
}
bool StackEmpty(LinkStack S)
{
    //判断是否是一个空的链栈
    if (S->next == nullptr)
        return true;
    else
        return false;
}
bool Push(LinkStack &S, char x)
{
    //将元素x进行入栈操作
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    if (p == nullptr)
        return false; //内存分配失败
    p->data = x;      //使用结点s保存数据元素x
    p->next = S->next;
    S->next = p; //修改栈顶指针
    return true;
}
bool Pop(LinkStack &S, char &x)
{
    //将栈顶元素进行出栈操作
    if (S->next == nullptr)
        return false; //栈空，报错
    LinkNode *p = S->next;
    x = p->data;       //取出栈顶元素
    S->next = p->next; //修改栈顶指针
    free(p);
    return true;
}
bool BracketCheck(char str[], int length)
{
    LinkStack S;
    InitLinkStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(S, str[i]); //扫描到左括号入账
        }
        else
        {
            if (StackEmpty(S))
                return false; //扫描到右括号且栈空，匹配失败
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
    char str[20];
    cout << "请输入“()”,”{}“,”[]“：" << endl;
    gets(str); //从键盘输入一串括号字符
    int len;
    len = strlen(str); //获取字符长度
    cout << (BracketCheck(str, len) ? "括号匹配正确" : "括号匹配错误");
}
