
// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <bits/stdc++.h>
using namespace std;
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}
int _mergeSort(int arr[], int temp[], int left, int right) {
	int mid, inversion_count = 0;
	if (left < right)
	{
		mid = (left + right) / 2;
		inversion_count += _mergeSort(arr, temp, left, mid);
		inversion_count += _mergeSort(arr, temp, mid + 1, right);

		inversion_count += merge(arr, temp, left, mid + 1, right);

	}
	return inversion_count;


}
int merge(int arr[], int temp[], int left, int mid, int right)
{
	int i = left;
	int j = mid;
	int k = left;
	int inversion_count = 0;
	while (i < mid && j <= right)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			inversion_count += (mid - i);
		}
	}
	while (i < mid)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inversion_count;

}

// Driver code
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = mergeSort(arr, n);
	cout << " Number of inversions are " << ans;
	return 0;
}

