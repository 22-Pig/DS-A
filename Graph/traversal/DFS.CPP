#define MAX_VERTEX_NUM 100 //最大结点数
bool visited[MAX_VERTEX_NUM];
void DFSTraverse(Graph G)
{
    for (v = 1; v <= G.versum; v++)
    {
        visited[v] = false; //初始化访问标记数组
    }

    for (v = 1; v <= G.versum; v++)
    {
        if (!visited[v])
            DFS(G, v);
    }
}

void DFS(Graph G, int v)
{
    visit(v);                                                        //访问顶点v
    visited[v] = true;                                               //标记已访问
    for (w = FirstNeighbor(G, v); w >= 1; w = NextNeighbor(G, v, w)) // w为u的尚未访问的邻接结点
        if (!visited[w])
        {
            DFS(G, w);
        }
}
