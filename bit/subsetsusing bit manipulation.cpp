#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
void subsets(vector<char> v, int n)
{


	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)))
				cout << v[j] << " ";

		}
		cout << endl;
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
	vector<char> v;
	char temp;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	subsets(v, n);

	return 0;

}