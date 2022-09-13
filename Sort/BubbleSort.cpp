//交换
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
//冒泡排序
void BubbleSort(int A[], int n)
{
    int i;
    int j;
    //冒泡排序，每次都把最小的数移到最前面
    for (i = 0; i < n - 1; i++)
    {
        bool flag = false; //标记此次排序是否发生交换
        for (j = n - 1; j > i; j--)
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        if (flag == false)
            return; //本次排序没有发生交换，说明表已经有序
    }
}
