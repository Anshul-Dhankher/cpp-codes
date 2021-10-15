#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
void solve(string s, int index, int n)
{

	if (index == n - 1)
	{
		cout << s << endl;
		return;
	}
	for (int i = index; i < n; i++)
	{
		swap(s[i], s[index]);
		solve(s, index + 1, n);
		swap(s[i], s[index]);
	}
}

int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	//solve(s, 0, s.length());
	sort(s.begin(), s.end());
	cout << s << endl;
	while (next_permutation(s.begin(), s.end()))
		cout << s << endl;





	return 0;

}