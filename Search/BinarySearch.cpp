typedef struct
{
    int *data;
    int MaxSize, length;
} SeqList;

int Binary_Search(SeqList L, int key)
{
    int low = 0;
    int high = L.length - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2; // 取中间位置
        if (L.data[mid] == key)
            return mid; // 查找成功则返回其所在位置
        else if (L.data[mid] > key)
            high = mid - 1; // 从前半部分继续查找
        else
            low = mid + 1; // 从后半部分继续查找
    }
    return -1; // 查找失败，返回-1
}