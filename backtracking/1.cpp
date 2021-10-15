#include<bits/stdc++.h>


using namespace std;
int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, n, k, d;

	cin >> t;



	while (t--) {
		cin >> n >> k >> d;
		int arr[n];
		long long int s = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			s += arr[i];
		}
		if (s / k > 0)
		{
			if (s / k > d)
				cout << d << endl;
			else
				cout << s / k << endl;
		}
		else
			cout << 0 << endl;
	}



	return 0;

}