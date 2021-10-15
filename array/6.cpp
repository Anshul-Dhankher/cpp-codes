int doUnion(int a[], int n, int b[], int m)  {
    set<int> x(a, a + n);
    set<int> y(b, b + m);
    vector<int> z(n + m);
    auto it = set_union(x.begin(), x.end(), y.begin(), y.end(), z.begin());

    z.resize(it - z.begin());

    return z.size();

}


