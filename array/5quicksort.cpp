#include<bits/stdc++.h>
using namespace std;


int main() {


#ifndef ONLINE_JUGDE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int x;
    vector<int> v;
    while (cin >> x)
        v.push_back(x);

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}




