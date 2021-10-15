class Solution {
public:
	std::vector <std::vector<int> > result;
	bool issafe(std::vector<std::vector<int>> &v, int x, int y)
	{
		int i, j;
		for (i = x - 1; i >= 0; i--)
		{
			if (v[i][y] == 1)
				return false;
		}
		for (i = x - 1, j = y - 1; i >= 0 && j >= 0 ; i--, j--)
		{
			if (v[i][j] == 1)
				return false;
		}
		for (i = x - 1, j = y + 1; i >= 0 && j < v.size(); i--, j++)
		{
			if (v[i][j] == 1)
				return false;
		}
		return true;
	}


	bool solve(std::vector<std::vector<int>> &v, int x)
	{
		if (x == v.size())
		{
			std::vector<int> sl;
			for (int i = 0; i < v.size(); i++)
			{
				for (int j = 0; j < v[i].size(); j++)
				{
					if (v[i][j] == 1)
						sl.push_back(j + 1);
				}
			}
			result.push_back(sl);

			return true;

		}
		bool res = false;
		for (int j = 0; j < v.size(); j++)
		{
			if (issafe(v, x, j))
			{
				v[x][j] = 1;
				res = solve(v, x + 1) || res;
				v[x][j] = 0;
			}
		}
		return res;
	}

	vector<vector<int>> nQueen(int n) {
		result.clear();
		vector<vector<int>> v(n, vector<int>(n, 0));
		if (solve(v, 0))
		{
			sort(result.begin(), result.end());
			return result;
		}
		else
		{
			return {};
		}

	}
};