

#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (arr[i] >= 0 && i < n)
			i += 1;
		while (arr[j] < 0 && j >= 0)
			j -= 1;
		if (i < j)
			swap(arr[i], arr[j]);

	}
	if (i == 0 || i == n)
		return;

	int k = 0;
	while (k < n && i < n)
	{
		swap(arr[k], arr[i]);
		k += 2;
		i += 1;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {2, 3, -4, -1, 6, -9};

	int n = sizeof(arr) / sizeof(arr[0]);

	rearrange(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";


	return 0;
}

