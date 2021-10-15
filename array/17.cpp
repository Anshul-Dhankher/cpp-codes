class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        map<int, int> mp;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < k)
            {
                if (mp[k - arr[i]])
                {
                    c += mp[k - arr[i]];
                    mp[arr[i]]++;
                }
                else
                    mp[arr[i]]++;
            }
        }
        return c;

    }
};