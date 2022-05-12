#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

struct ElemType
{
    int value;
};

/* 树的存储——孩子兄弟表示法 */
typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstChild, *nextSibling; // 第一个孩子和右兄弟指针
} CSNode, *CSTree;
