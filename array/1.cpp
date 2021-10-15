#include<bits/stdc++.h>

using namespace std;

int main()
{

#ifndef ONLINE_JUGDE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	int x;
	vector<int> v;
	while (cin >> x)
	{
		v.push_back(x);
	}
	for (auto it = v.rbegin(); it != v.rend(); ++it)
		cout << *it << " ";




	return 0;
}
