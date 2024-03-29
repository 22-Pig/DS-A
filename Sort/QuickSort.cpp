//用第一个元素将待排序的序列划分成左右两个部分
int Partition(int A[], int low, int high)
{
    int pivot = A[low]; //第一个元素作为基准
    while (low < high)
    { //用low和high搜索基准最终位置
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high]; //比基准小的数移动到左边
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low]; //比基准大的数移动到右边
    }
    A[low] = pivot; //基准存放到最终位置
    return low;     //返回存放基准的最终位置
}

//快速排序
void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {                                           //递归跳出的条件
        int pivotpos = Partition(A, low, high); //划分
        QuickSort(A, low, pivotpos - 1);        //划分左子表
        QuickSort(A, pivotpos + 1, high);       //划分右子表
    }
}
