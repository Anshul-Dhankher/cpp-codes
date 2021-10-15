#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int m;
        cin >> m;
        sort(arr, arr + n);
        int min = arr[m - 1] - arr[0];
        for (int i = 1; i < n - m + 1; i++)
        {
            if (arr[i + m - 1] - arr[i] < min)
                min = arr[i + m - 1] - arr[i];
        }
        cout << min << endl;

    }
    return 0;
}