#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize]; // 静态数组存放队列中元素
    int front, rear;        // 队头指针和队尾指针
    int size;               // 队列当前长度
} SqQueue;

/* 初始化队列 */
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = Q.size = 0; // 初始化队头、队尾指针指向0
}

/* 返回当前队列的长度 */
int QueueLength(SqQueue &Q)
{
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

/* 判断队列是否为空 */
bool QueueEmpty(SqQueue Q)
{
    if (Q.size == 0) // 队空条件
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 新元素入队 */
bool EnQueue(SqQueue &Q, ElemType x)
{
    if (Q.size == MaxSize)
    {
        return false; // 队列满，报错
    }
    Q.data[Q.rear] = x;              // 将x插入队尾
    Q.rear = (Q.rear + 1) % MaxSize; // 队尾指针加1取模
    Q.size++;
    return true;
}

/* 出队操作 */
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if (Q.size == 0)
    {
        return false; // 队列空，报错
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.size--;
    return true;
}

/* 读取队头元素 */
bool GetHead(SqQueue Q, ElemType &x)
{
    if (Q.size == 0)
    {
        return false; // 队空，报错
    }
    x = Q.data[Q.front];
    return true;
}

void printQueue(SqQueue Q)
{
    if (Q.size == 0)
    {
        return;
    }
    for (int i = 0; i < Q.size; i++)
    {
        ElemType x = Q.data[Q.front];
        printf("%d", x);
        Q.front += 1;
    }
    printf("\n");
}

int main()
{
    SqQueue Q;    // 声明一个顺序队列
    InitQueue(Q); // 初始化循环队列
    printf("正在创建顺序队列，请输入队列元素，以-1结束：\n");

    ElemType elem = 0; //存储出队元素
    while (1)
    {
        scanf("%d", &elem);
        if (elem != -1)
        {
            EnQueue(Q, elem);
        }
        else
        {
            break;
        }
    }

    printf("队列建立成功\n");

    printQueue(Q);

    bool ret;
    ret = DeQueue(Q, elem);
    if (ret)
        printf("出队元素为：%d\n", elem);

    printQueue(Q);
}
