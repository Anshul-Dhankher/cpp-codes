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
		v.push_back(x);

	auto minmax = minmax_element(v.begin(), v.end());

	cout << "MINIMUM ELEMENT:" << *minmax.first << endl << "MAXIMUM ELEMENT:" << *minmax.second;





	return 0;
}
