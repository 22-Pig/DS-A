//希尔排序,传入数组以及其长度
void ShellSort(int A[], int n)
{
    int d, i, j;
    //将A[0]作为暂存单元，j<=0时，插入位置已到
    for (d = n / 2; d >= 1; d = d / 2)
    { //步长变化
        for (i = d + 1; i <= n; i++)
        { //轮流切换子表
            if (A[i] < A[i - d])
            {                //需要将A[i]插入有序增量子表
                A[0] = A[i]; //暂存在A[0]
                for (j = i - d; j > 0 && A[j] > A[0]; j = j - d)
                {
                    A[j + d] = A[j]; //记录后移，寻找插入位置
                }
                A[j + d] = A[0]; //插入
            }
        }
    }
}
