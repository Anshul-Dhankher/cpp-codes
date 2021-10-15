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

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> G[n + 1];

    for (int i = 0; i < m; i++)
    {
        ll a, b, wt;
        cin >> a >> b >> wt;
        G[a].push_back({b, wt});
        G[b].push_back({a, wt});
    }



    //dijkstra algorithm

    set<pair<ll, ll>> s; //weight node
    vector<ll> dis(n + 1, LLONG_MAX);
    dis[1] = 0;

    s.insert({0, 1});
    while (!s.empty())
    {
        auto ele = *s.begin();
        s.erase(s.begin());
        ll p = ele.second;
        ll dis_parent = ele.first;
        for (auto nb : G[p])
        {
            if (dis_parent + nb.second < dis[nb.first])
            {
                auto f = s.find({dis[nb.first], nb.first});
                if (f != s.end())
                    s.erase(f);
                dis[nb.first] = dis_parent + nb.second;

                s.insert({dis[nb.first], nb.first});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << dis[i] << " ";
    cout << endl;


}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;

}