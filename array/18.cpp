
class Solution
{
public:
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {
        map<int, int> mp;
        vector<int> v;
        int i, j, k;
        for (i = 0; i < n1; i++)
        {
            if (mp[A[i]] == 0)
                mp[A[i]]++;
        }
        for (j = 0; j < n2; j++)
        {
            if (mp[B[j]] == 1)
                mp[B[j]]++;
        }
        for (k = 0; k < n3; k++)
        {
            if (mp[C[k]] == 2)
                mp[C[k]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->second == 3)
                v.push_back(it->first);
        }

        return v;
    }

};