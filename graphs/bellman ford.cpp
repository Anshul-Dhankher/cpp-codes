int bellman_ford(vector<vector<int>> edges, int n)
{
    vector<int> dis(n, INT_MAX);
    dis[0] = 0;

    int v = n - 1;
    for (int i = 1; i <= v; i++)
    {
        for (auto edg : edges)
        {
            int src = edg[0];
            int des = edg[1];
            int wt = edg[2];
            if (dis[src] + wt < dis[des] && dis[src] != INT_MAX)
                dis[des] = dis[src] + wt;
        }
    }
    for (int i = 0; i < n; i++)
        cout << dis[i] << " ";

    //checking negative cycle
    for (auto edg : edges)
    {
        int src = edg[0];
        int des = edg[1];
        int wt = edg[2];
        if (dis[src] + wt < dis[des] && dis[src] != INT_MAX)
        {
            return 1;
        }
    }
    return 0;


}