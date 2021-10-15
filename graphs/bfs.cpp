#include<bits/stdc++.h>

typedef long long int ll;
#define MOD 1000000007
#define INF INT_MAX
#define max_ele 10
using namespace std;
void bfs(int A[][max_ele], int n, int start)
{
	bool visited[n + 1] = {0};
	queue<int> q;
	std::vector<int> p(n), d(n, 0);
	q.push(start);
	visited[start] = 1;
	cout << start << "->";
	p[start] = -1;
	while (!q.empty())
	{
		int ele = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (A[ele][i] == 1 && visited[i] == 0)
			{
				q.push(i);
				cout << i << "->";
				visited[i] = 1;
				p[i] = ele;
				d[i] = d[ele] + 1;
			}
		}

	}
	cout << endl;
	std::vector<int> path;//path from start to any node(shortest path)
	if (!visited[7])
		cout << "NO path" << endl;
	for (int i = 2; i != -1; i = p[i])
		path.push_back(i);
	reverse(path.begin(), path.end());
	cout << "path length is: " << path.size() << endl;
	for (auto i : path)
		cout << i << " ";

}
int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int A[max_ele][max_ele];
	memset(A, 0, sizeof(A));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> A[i][j];
	}
	bfs(A, n, 5);




	return 0;

}