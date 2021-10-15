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
vector<vector<int>> ranks_times;

void pre_compute()
{
	for (int r = 1; r <= 8; r++)
	{
		vector<int> v;
		int sum_prev = 0;
		for (int i = 1; i <= 1000; i++)
		{
			v.push_back(sum_prev + i * r);

			sum_prev += i * r;
		}
		ranks_times.push_back(v);
	}
}

bool ispossible(int cooks[], int n, int p, int mid)
{

	int prata_cooked = 0;
	for (int i = 0; i < n; i++)
	{

		int pos = lower_bound(ranks_times[cooks[i] - 1].begin(), ranks_times[cooks[i] - 1].end(), mid) - ranks_times[cooks[i] - 1].begin();
		if (pos == 1000)
			return true;

		if (ranks_times[cooks[i] - 1][pos] == mid)
			prata_cooked += (pos + 1);
		else
			prata_cooked += pos;

		if (prata_cooked >= p)
			return true;
	}
	return false;

}

void solve()
{
	int p;
	cin >> p;
	int n;
	cin >> n;
	int cooks[n];
	for (int i = 0; i < n; i++)
		cin >> cooks[i];



	int start = 1;
	int end = 4004000;
	int ans = -1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;




		if (ispossible(cooks, n, p, mid))
		{
			ans = mid;
			end = mid - 1;

		}
		else
		{
			start = mid + 1;
		}
	}

	cout << ans << endl;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pre_compute();
	ll t;
	cin >> t;
	while (t--)
		solve();

	return 0;

}