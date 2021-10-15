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
int n, m;
vector<vector<int>> G;
vector<int> visited;
vector<int> dis;
vector<int> parent;
void bfs(int start, int &ans)
{
	visited[start] = 1;
	dis[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (auto ngr : G[node])
		{
			if (!visited[ngr])
			{
				visited[ngr] = 1;
				parent[ngr] = node;
				dis[ngr] = dis[node] + 1;
				q.push(ngr);
			}
			else if (parent[node] != ngr)
			{
				ans = min(ans, dis[node] + dis[ngr] + 1);
			}
		}
	}
}

void solve()
{
	cin >> n >> m;
	G.resize(n + 1);
	visited.resize(n + 1);
	dis.resize(n + 1);
	parent.resize(n + 1);
	fill(visited.begin(), visited.end(), 0);
	fill(dis.begin(), dis.end(), -1);
	fill(parent.begin(), parent.end(), -1);

	int ans = n + 1;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		bfs(i, ans);
		fill(visited.begin(), visited.end(), 0);
		fill(dis.begin(), dis.end(), -1);
		fill(parent.begin(), parent.end(), -1);

	}
	if (ans == n + 1)
	{
		cout << "No cycle" << endl;
	}
	else
	{
		cout << "shortest cycle of length:" << ans << endl;
	}


}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	solve();

	return 0;

}