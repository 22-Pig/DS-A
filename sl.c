typedef struct
{
    char num[8];  // 数据域
    char name[8]; // 数据域
    int score;    // 数据域
} ElemType;

typedef struct Lnode
{
    ElemType data;        // 数据域
    struct student *next; // 指针域
} Lnode, *LinkList;

LinkList L;