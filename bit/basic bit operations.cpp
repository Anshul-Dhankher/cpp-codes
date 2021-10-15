#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
void setbit(int &n, int i)
{
	n = n | (1 << i);
}
void  clearbit(int &n, int i)
{
	n &= ~(1 << i);
}
int getbit(int &n, int i)
{
	return (n & (1 << i)) != 0;
}
void invertbit(int &n, int i)
{
	n ^= (1 << i);
}
void updatebit(int &n, int i, int b)
{
	n |= (b << i);
}

int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x;
	cin >> x;
	int i;
	cin >> i;
	updatebit(x, i, 1);
	cout <<  x << endl;



	return 0;

}