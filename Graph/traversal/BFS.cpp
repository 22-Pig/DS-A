#define MAX_VERTEX_NUM 100    //最大结点数
bool visited[MAX_VERTEX_NUM]; //访问标记数组

void BFSTraverse(Graph G)
{
    for (int i = 1; i <= G.vexnum; i++)
    {
        visited[i] = false; //初始化标记数组
    }

    InitQueue(Q); //初始化辅助队列Q
    for (int i = 1; i <= G.vexnum; i++)
    {
        if (!visited[i])
            BFS(G, i);
    }
}

//广度优先遍历
void BFS(Graph G, int v)
{                      //从顶点v出发，广度优先遍历图G
    visit(v);          //访问初始顶点v
    visited[v] = true; //对v做已访问标志
    Enqueue(Q, v);     //顶点v入队列Q
    while (!isEmpty(Q))
    {
        DeQueue(Q, v); //顶点v出队列
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        {
            if (!visited[w])
            {
                visit(w); //访问顶点w
                visited[w] = true;
                EnQueue(Q, w); //顶点w入队列
            }
        }
    }
}
