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
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[largest] < arr[left])
		largest = left;

	if (right < n && arr[largest] < arr[right])
		largest = right;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void build_heap_optimized(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
}

void heapsort(int arr[], int n)
{
	build_heap_optimized(arr, n);

	for (int i = n - 1; i > 0; i--)
	{
		cout << arr[0] << " ";
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
	cout << arr[0] << endl;

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	heapsort(arr, n);
	//if we contruct a min heap we get a max heaped array as here after heapifying we just storing them at the end of the array if we were just storing them at the same time or we  were printing them we would be getting the same heap.

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;

}