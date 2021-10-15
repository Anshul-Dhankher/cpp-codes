

#include <bits/stdc++.h>
using namespace std;

int trappingWater(int arr[], int n)
{
    int i, w = 0;
    int LA[n], RA[n];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];

        LA[i] = max;
    }
    max = 0;
    for (i = n - 1; i >= 0; i--)
    {
        if (max < arr[i])
            max = arr[i];

        RA[i] = max;
    }

    for (int i = 1; i < n - 1; i++)
    {

        int s = LA[i] > RA[i] ? RA[i] : LA[i];
        if (s > arr[i])
            w += s - arr[i];
    }
    return w;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {6, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << trappingwater(arr, n);
}
