/**
 *    Author:ANSHUL DHANKHER
 *     YMCA CE-2023
 *    KEEP HUSTLING!!!
**/

#include<bits/stdc++.h>

typedef long long int ll;
#define MOD 1000000007
#define INF INT_MAX
using namespace std;

void dfs(int start, vector<vector<int>>&G, vector<bool> &visited, vector<int> &comp)
{
    visited[start] = 1;
    comp.push_back(start);
    for (auto ele : G[start])
    {
        if (!visited[ele])
        {
            dfs(ele, G, visited, comp);
        }
    }
}
int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<bool> visited(n, 0);
    vector<int> comp;
    vector<int> ans;
    vector<vector<int>> G(n);

    for (int i = 0; i < astronaut.size(); i++)
    {
        G[astronaut[i][0]].push_back(astronaut[i][1]);
        G[astronaut[i][0]].push_back(astronaut[i][0]);

    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, G, visited, comp);
            ans.push_back(comp.size());
            comp.clear();
        }
    }
    int final_ans = (n * (n - 1)) / 2;
    for (int i = 0; i < ans.size(); i++)
    {
        final_ans -= ((ans[i] * (ans[i] - 1)) / 2);
    }
    return final_ans;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    cout << journeyToMoon(n, edges) << endl;


    return 0;

}
