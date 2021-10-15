#include<bits/stdc++.h>
using namespace std;


int main() {


#ifndef ONLINE_JUGDE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> v = {2, 4, 5, 6, 7};
	rotate(v.begin(), v.begin() + 2, v.end());//left rotation

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	cout << endl;

	rotate(v.begin(), v.begin() + v.size() - 2, v.end());//right rotation


	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}




