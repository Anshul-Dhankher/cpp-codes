#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;

void subulit(std::vector<int> v, std::vector<vector<int>> &res, std::vector<int> &ss, int index)
{
	res.push_back(ss);
	for (int i = index; i < v.size(); i++)
	{
		ss.push_back(v[i]);
		subulit(v, res, ss, i + 1);
		ss.pop_back();
	}
	return;
}

vector<vector<int>> subset(std::vector<int> v)
{
	vector<int> ss;
	std::vector<std::vector<int>> res;
	int index = 0;
	subulit(v, res, ss, index);

	return res;
}


int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int temp;
	std::vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	std::vector<std::vector<int>> res = subset(v);

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}





	return 0;

}