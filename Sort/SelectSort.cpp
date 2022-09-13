//选择排序：从待排序元素中比较全部，选择最小的加入有序子序列，而不是每次找到更小的值就交换（频繁交换增加复杂度）
void SelectSort(int A[], int n)
{
    //共排序n-1躺
    for (int i = 0; i < n - 1; i++)
    {
        int min = i; //记录最小元素下标
        for (int j = i + 1; j < n; j++)
        {
            if (A[min] > A[j])
            {
                min = j; //更新最小元素下标
            }
        }

        //若更新了最小元素下标，则需交换（需移动元素三次）
        if (min != i)
        {
            swap(A[i], A[min]);
        }
    }
}

//辅助函数
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
