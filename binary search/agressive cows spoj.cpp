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

bool ispossible(vector<int> &stalls, int n, int c, int mid)
{
    int i = 0;
    int cows_assigned = 1;
    while (cows_assigned < c)
    {
        i = lower_bound(stalls.begin(), stalls.end(), mid + stalls[i]) - stalls.begin();
        if (i == n)
            return false;
        else
            cows_assigned++;
    }
    return true;

}

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> stalls;

    int min_df = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        stalls.push_back(temp);
    }
    sort(stalls.begin(), stalls.end());
    for (int i = 0; i < n - 1; i++)
    {
        min_df = min(min_df, stalls[i + 1] - stalls[i]);

    }
    int start = min_df;
    int end = stalls[n - 1] - stalls[0];

    int mid;
    int ans = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (ispossible(stalls, n, c, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << ans << endl;


}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;

}