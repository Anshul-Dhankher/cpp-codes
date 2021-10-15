#define ll long long int
class Solution
{
public:
    //Function to find minimum number of pages.

    bool ispossible(int arr[], int n, int m, int mid)
    {
        int teams = 1;
        int curr_sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
                return false;

            if (curr_sum + arr[i] > mid)
            {
                teams++;
                curr_sum = arr[i];
                if (teams > m)
                    return false;
            }
            else
                curr_sum += arr[i];
        }
        return true;
    }

    int findPages(int arr[], int n, int m)
    {
        ll s = accumulate(arr, arr + n, 0);
        ll start = *max_element(arr, arr + n);
        ll end = s;
        ll mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (ispossible(arr, n, m, mid))
                end = mid - 1;
            else
                start = mid + 1;
        }

    }
};