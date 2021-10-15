#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
bool col[16], dg1[16], dg2[16], reserved[8][8];
int c = 0;
void solve(int r) {
	if (r == 8)
	{
		c++;
		return;
	}
	for (int k = 0; k < 8; k++)
	{
		if (col[k] || dg1[r + k] || dg2[r - k + 7] || reserved[r][k])
			continue;
		col[k] = dg1[r + k] = dg2[r - k + 7] = true;
		solve(r + 1);
		col[k] = dg1[r + k] = dg2[r - k + 7] = false;

	}
}


int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 0; i < 8; i++)
		col[i] = dg1[i] = dg2[i] = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char x;
			cin >> x;
			if (x == '*')
				reserved[i][j] = 1;
			else
				reserved[i][j] = 0;
		}
	}
	solve(0);
	cout << c << endl;



	return 0;

}