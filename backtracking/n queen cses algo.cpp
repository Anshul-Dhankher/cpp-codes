#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
bool col[16], dg1[16], dg2[16];
int c = 0;
std::vector<std::vector<int>> res;
std::vector<int> v;
void solve(int r, int n) {
	if (r == n)
	{
		c++;


		res.push_back(v);
		v.clear();
		return;
	}
	for (int k = 0; k < n; k++)
	{
		if (col[k] || dg1[r + k] || dg2[r - k + n - 1] )
			continue;
		v.push_back(k + 1);
		col[k] = dg1[r + k] = dg2[r - k + n - 1] = true;
		solve(r + 1, n);
		col[k] = dg1[r + k] = dg2[r - k + n - 1] = false;

	}
}


int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		col[i] = dg1[i] = dg2[i] = false;
	res.clear();
	solve(0, n);
	cout << c << endl;
	sort(res.begin(), res.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}



	return 0;

}