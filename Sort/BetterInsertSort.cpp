//优化，使用哨兵+折半查找
void BetterInsertSort(int A[], int n)
{
    int i, j, low, high, mid;
    //依次将A[2]-A[n]插入前面已经排好序的序列
    for (i = 2; i <= n; i++)
    {
        //将A[i]暂存到A[0]中
        A[0] = A[i];
        //设置折半范围
        low = 1;
        high = i - 1;
        //进行折半查找
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (A[mid] > A[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        //统一后移元素，空出插入位置
        for (j = i - 1; i >= low; j++)
            A[j + 1] = A[j];
        A[low] = A[0];
    }
}
