#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;

/* 可用于操作系统文件分配表FAT */

struct Node
{
    ElemType data;
    int next;
};

typedef struct
{
    ElemType data;
    int next;
} SLinkList[MaxSize];

void testSLinkList()
{
    struct Node x;
    printf("sizeX=%d\n", sizeof(x));

    struct Node a[MaxSize];
    printf("sizeA=%d\n", sizeof(a));

    SLinkList b;
    printf("sizeB=%d\n", sizeof(b));
}

int main(int argc, char const *argv[])
{
    testSLinkList();
    return 0;
}
