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

void solve()
{
	int n;
	cin >> n;
	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> parent[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int temp = parent[i];
		int ans = 1;
		while (temp != i)
		{
			ans++;
			temp = parent[temp];
		}
		cout << ans << " ";
	}
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

	ll t;
	cin >> t;
	while (t--)
		solve();

	return 0;

}