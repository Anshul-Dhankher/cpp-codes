

#include <bits/stdc++.h>
using namespace std;

bool checkpalindrome(int n)
{
    deque<int> d;
    while (n)
    {
        int x = n % 10;
        n = n / 10;
        d.push_front(x);
    }
    while (d.size() != 1)
    {
        if (d.front() == d.back())
        {
            d.pop_back();
            d.pop_front();
        }
        else
            return false;
    }
    return true;
}

int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (checkpalindrome(a[i]) == false)
            return 0;
    }
    return 1;
}


int main()
{
#ifndef ONLINE_JUGDE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << PalinArray(arr, n) << endl;

    }
    return 0;
}
