bool find3Numbers(int arr[], int N, int X)
{
    sort(arr, arr + N);
    for (int i = 0; i < N - 2; i++)
    {
        int l = i + 1;
        int r = N - 1;
        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == X)
                return true;
            else if (arr[i] + arr[l] + arr[r] > X)
                r--;
            else
                l++;
        }
    }
    return false;
}