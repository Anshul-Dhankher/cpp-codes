#include<bits/stdc++.h>
using namespace std;

#define f(i,x,n) for(int i=x;i<=n;i++)
#define pb push_back
#define ll long long
#define ff first
#define ss second

int main() {
    bool f = true;
    int n;
    cin >> n;
    vector<int> l(n + 1);
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, -1));
    f(i, 1, n) {
        cin >> l[i];
        f(j, 1, i - 1) {
            ans[i][j] = 0;
        }
        ans[i][i] = l[i];
    }

    f(k, 1, n) {
        int i, j;
        i = k;
        j = k;
        int x = l[k] - 1;
        while (x--) {
            if (i > 0 and ans[i - 1][j] == 0)ans[--i][j] = l[k];
            else if (j > 0 and ans[i][j - 1] == 0)ans[i][--j] = l[k];
            else if (i < n and ans[i + 1][j] == 0)ans[++i][j] = l[k];
            else if (j < n and ans[i][j + 1] == 0)ans[i][++j] = l[k];
            else break;
        }
        if (x > 0) {
            f = false;
            cout << -1 << endl;
        }
    }
    if (f)
        f(i, 1, n) {
        f(j, 1, i) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}