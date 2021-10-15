#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
int countsetbit(int n)
{
	int count = 0;
	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}
int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x;
	cin >> x;
	cout << countsetbit(x) << endl;
	cout << __builtin_popcount(x) << endl;//another method to count set bits in an binary number;


	return 0;

}