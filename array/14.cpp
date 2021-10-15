
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		bool flag = next_permutation(nums.begin(), nums.end());
		if (flag == 0)
			sort(nums.begin(), nums.end());


	}
};