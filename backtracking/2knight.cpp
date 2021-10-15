#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		ll ans = pow(i, 2)  * (pow(i, 2) - 1) / 2 - 4 * (i - 1) * (i - 2);
		cout << ans << endl;
	}



	return 0;

}