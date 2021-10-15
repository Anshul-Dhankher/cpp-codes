class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> final;
        sort(intervals.begin(), intervals.end());
        int i = 1;
        int n = intervals.size();
        int a = intervals[0][0];
        int b = intervals[0][1];
        while (i < n)
        {
            if ((a <= intervals[i][0] && b >= intervals[i][0]) || (a <= intervals[i][1] && b >= intervals[i][1]))
            {
                a = min(a, intervals[i][0]);
                b = max(b, intervals[i][1]);
            }
            else {
                vector<int> v{a, b};
                final.push_back(v);
                a = intervals[i][0];
                b = intervals[i][1];
            }
            i++;
        }
        vector<int> v{a, b};
        final.push_back(v);
        return final;
    }
};