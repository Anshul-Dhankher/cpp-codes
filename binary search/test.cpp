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

int rotatedbs(int arr[], int n, int ele)
{
	int l = 0, r = n - 1;
	int mid;
	int first = arr[0];
	while (l <= r)
	{
		mid = l + (r - l) / 2;

		if (arr[mid] == ele)
			return mid;
		bool am_big = arr[mid] >= first;
		bool ele_big = ele >= first;
		if (am_big == ele_big)
		{
			if (arr[mid] > ele)
				r = mid - 1;
			else
				l = mid + 1;
		}
		else
		{
			if (am_big)
				l = mid + 1;
			else
				r = mid - 1;
		}
	}
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << rotatedbs(arr, n, 5) << endl;

	return 0;

}