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
vector<int> parent;
bool dfs(int start, int color)
{
	visited[start] = color;
	for (auto nb : G[start])
	{
		if (visited[nb] == 0)
		{
			parent[nb] = start;
			bool ans = dfs(nb, 3 - color);
			if (ans == false)
				return false;
		}
		else if (parent[start] != nb && color == visited[nb])
			return false;
	}
	return true;
}

void solve()
{
	cin >> n >> m;
	G.resize(n + 1);
	visited.resize(n + 1);
	parent.resize(n + 1);
	fill(visited.begin(), visited.end(), 0);
	fill(parent.begin(), parent.end(), -1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			bool ans = dfs(i, 1);
			if (ans == false)
			{
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << visited[i] << " ";
	cout << endl;

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