#include <stdio.h>
#include <stdlib.h>
#define InitSize 10

int *B = (int *)malloc(InitSize * sizeof(int)); //辅助数组B

// A[low///mid]和A[mid+1,high]各自有序，将两个部分归并
void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    for (k = low; k <= high; k++)
        B[k] = A[k]; //将A中所有元素复制到B中

    //归并
    for (i = low, k = low, j = mid + 1; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
            A[k] = B[i++]; //将较小的元素赋值到A中
        else
            A[k] = B[j++];
        //将剩余的元素也赋值到A中
        while (i <= mid)
            A[k++] = B[i++];
        while (j <= high)
            A[k++] = B[j++];
    }
}

void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        //从中间划分
        int mid = (low + high) / 2;
        //对左半部分归并排序
        MergeSort(A, low, mid);
        //对右半部分归并排序
        MergeSort(A, mid + 1, high);
        //归并
        Merge(A, low, high);
    }
}
