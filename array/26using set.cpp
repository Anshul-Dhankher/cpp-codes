#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        unordered_set<int> a, b;
        for (int i = 0; i < m; i++)
        {
            int temp;
            cin >> temp;
            a.insert(temp);
        }
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            b.insert(temp);
        }
        int flag = 1;
        for (auto i : b)
        {
            if (a.find(i) == a.end())
                flag = 0;
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }
    return 0;
}