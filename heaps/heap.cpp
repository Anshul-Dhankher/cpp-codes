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

int gettop(int heap[], int sz)
{
	if (sz == 0)
	{
		cout << "heap is empty" << endl;
		return -1;
	}
	return heap[1];
}

void Insert_into_heap(int heap[], int &sz, int ele)
{
	if (sz == 100)
	{
		cout << "heap is full" << endl;
		return;
	}

	int i = sz + 1;
	heap[i] = ele;
	while (ele >  heap[i / 2] && i > 1)
	{
		swap(heap[i], heap[i / 2]);
		i = i / 2;
	}

	sz++;

}

void Pop(int heap[], int &sz)
{
	swap(heap[1], heap[sz]);
	sz--;
	int i = 1;
	int lchild = 2 * i, rchild = 2 * i + 1;

	while (lchild <= sz)
	{

		if (lchild < sz)
		{

			if (heap[i] > min(heap[lchild], heap[rchild]))
			{
				if (heap[lchild] > heap[rchild])
				{
					swap(heap[i], heap[rchild]);
					i = rchild;
				}
				else
				{
					swap(heap[i], heap[lchild]);
					i = lchild;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			if (heap[i] > heap[lchild])
			{
				swap(heap[i], heap[lchild]);
				i = lchild;
			}
			else
			{
				break;
			}
		}
		lchild = 2 * i;
		rchild = 2 * i + 1;




	}


}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int heap[101];
	int sz = 0;
	int arr[] = {2, 7, 4, 5, 1, 10, 8, 20, 15, 100, 99};
	//min heap;
	for (int i = 0; i < 11; i++)
		Insert_into_heap(heap, sz, arr[i]);



	//here is the sorted array using heap sort or we can save that we have a heap that
	//poping elements till its size turns to 0;

	while (sz > 0)
	{
		cout << "max element:" << gettop(heap, sz) << endl;
		for (int i = 1; i <= sz; i++)
			cout << heap[i] << " ";
		cout << endl << endl;
		Pop(heap, sz);
	}


	return 0;

}