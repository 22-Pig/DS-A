//建立大根堆
void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--)
    { //从后往前遍历所有非终端节点
        HeadAdjust(A, i, len);
    }
}

//将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len)
{
    A[0] = A[k]; // A[0]暂存子树的根节点
    for (int i = 2 * k; i < len; i *= 2)
    { //沿key较大的子节点向下筛选
        if (i < len && A[i] < A[i + 1])
            i++; //取key较大的子节点下标
        if (A[0] >= A[i])
            break; //筛选结束
        else
        {
            A[k] = A[i]; //将A[i]调整到双亲结点上
            k = i;       //修改k值，以便继续向下筛选
        }
    }
    A[k] = A[0]; //将被筛选结点放入最终位置
}
