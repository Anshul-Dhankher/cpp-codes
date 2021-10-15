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
vector<int> ans;
//vector<bool> visited;

vector<int> indegree;
void bfs(int start)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		ans.push_back(node);

		for (auto nb : G[node])
		{


			indegree[nb]--;
			if (indegree[nb] == 0)
			{
				q.push(nb);
			}

		}
	}
}


void solve()
{
	cin >> n >> m;
	G.resize(n + 1);

	indegree.resize(n + 1);


	fill(indegree.begin(), indegree.end(), 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		indegree[b]++;
	}



	bfs(1);
	if (ans.size() == n)
	{
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	else
		cout << "IMPOSSIBLE" << endl;


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