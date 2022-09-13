typedef struct //查找表的数据结构
{
    int *data;    //元素存储空间基质，建表时按实际长度分配，0号单源留空
    int TableLen; // 表的长度
} SSTable;

int searchSeq(SSTable ST, int key)
{
    // 引入哨兵元素，在创建查找表时，0号单元留空，预留给带查找元素关键字
    // 引入哨兵元素的目的是使得循环不必判断数组是否越界，可以避免很多不必要的判断语句，提高效率
    ST.data[0] = key; // 哨兵
    int i;
    for (i = ST.TableLen; ST.data[i] != key; --i)
        ; // 从后往前查找，满足i==0时，循环一定会跳出
    return i;
}
