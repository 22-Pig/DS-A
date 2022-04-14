int e = -1;
    if (ListDelete(L, 3, e))
    {
        printf("删除成功：%d\n", e);
    }
    else
    {
        printf("删除失败\n");
    }