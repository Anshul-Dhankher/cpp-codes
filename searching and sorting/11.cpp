
#include<bits/stdc++.h>
using namespace std;




int main()
{
#ifndef ONLINE_JUGDE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	vector<int> v;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int p;
		cin >> p;
		int s = 0;
		int j = upper_bound(v.begin(), v.end(), p) - v.begin();
		for (int k = 0; k < j; k++)
			s += v[k];

		cout << j << " " << s << endl;
	}

	return 0;
}