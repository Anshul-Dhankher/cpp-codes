

#include<bits/stdc++.h>
using namespace std;



int main()
{
#ifndef ONLINE_JUGDE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x;
    vector<int> v;

    while (cin >> x)
        v.push_back(x);

    int low = 0, mid = 0, high = v.size() - 1;

    while (mid <= high)
    {
        switch (v[mid])
        {
        case 0:
            swap(v[low], v[mid]);
            low++;
            mid++;
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(v[mid], v[high]);
            high--;

        }
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}