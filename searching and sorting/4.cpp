class Solution {
public:
	int countSquares(int N) {
		if (sqrt(N) - floor(sqrt(N)) == 0)
			return floor(sqrt(N)) - 1;

		return floor(sqrt(N));
	}
};