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

vector<pair<int, int>> edgelist;
int n;
vector<int> parent;
vector<int> Rank;

int find_parent_set(int i)
{
	if (parent[i] == -1)
		return i;
	return parent[i] = find_parent_set(parent[i]);
}

void Union_of_set(int i, int j)
{
	int parent_of_i = find_parent_set(i);
	int parent_of_j = find_parent_set(j);
	if (i != j)
	{
		if (Rank[parent_of_i] > Rank[parent_of_j])
		{
			swap(parent_of_i, parent_of_j);
		}
		parent[parent_of_i] = parent_of_j;
		Rank[parent_of_j] += Rank[parent_of_i];
	}
	else
	{
		//will form a cycle
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t;
	while (t--)
		solve();

	return 0;

}