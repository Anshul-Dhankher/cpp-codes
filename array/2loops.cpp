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

	pair<int, int> minmax;

	if (v.size() == 1)
	{	minmax.first = v[0];
		minmax.second = v[0];
	}

	else if (v.size() == 2)
	{
		if (v[0] > v[1])
		{	minmax.first = v[1];
			minmax.second = v[0];
		}
		else
		{
			minmax.first = v[0];
			minmax.second = v[1];
		}
	}
	else
	{
		for (int i = 2; i < v.size(); ++i)
		{
			if (v[i] > minmax.second)
				minmax.second = v[i];
			else if (v[i] < minmax.first)
				minmax.first = v[i];
		}
	}

	cout << "MINIMUM ELEMENT: " << minmax.first << endl << " MAXIMUM ELEMENT:" << minmax.second;


	return 0;
}
