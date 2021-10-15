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

int bs(int arr[], int l, int r, int ele)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] == ele)
            return mid + 1;
        else if (arr[mid] > ele)
            return bs(arr, l, mid - 1, ele);
        else
            return bs(arr, mid + 1, r, ele);
    }
    else
        return -1;
}

int mylowerbound(int arr[], int l, int r, int ele)
{
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] >= ele)

            r = mid - 1 ;

        else
            l = mid + 1;
    }
    return l  ;


}

int myupperbound(int arr[], int l, int r, int ele)
{
    int mid;

    while (l  <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] <= ele)
            l = mid + 1;

        else
            r = mid - 1;

    }
    return l ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 10;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << mylowerbound(arr, 0, n - 1, 1) << endl;
    cout << myupperbound(arr, 0, n - 1, 1)  << endl;


    return 0;

}