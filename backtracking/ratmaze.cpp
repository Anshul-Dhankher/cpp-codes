#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
bool issafe(vector<std::vector<int>>v, int x, int y, int n)
{
	if (x < n && y < n && v[x][y] == 1)
		return true;
	return false;
}

bool ratinmaze(std::vector<std::vector<int> > v, std::vector<std::vector<int>> &ans, int x, int y, int n)
{
	if (x == n - 1 && y == n - 1)
	{
		ans[x][y] = 1;
		return true;
	}
	if (issafe(v, x, y, n))
	{
		ans[x][y] = 1;
		if (ratinmaze(v, ans, x + 1, y, n))
			return true;
		if (ratinmaze(v, ans, x, y + 1, n))
			return true;
		ans[x][y] = 0;
		return false;

	}
	return false;

}



int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	std::vector<std::vector<int> > v(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];


	std::vector<std::vector<int> > ans(n, std::vector<int>(n, 0));
	if (ratinmaze(v, ans, 0, 0, n))
	{
		for (auto i : ans)
		{
			for (auto it : i)
			{
				cout << it << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "NO SOLUTION" << endl;
	}





	return 0;

}