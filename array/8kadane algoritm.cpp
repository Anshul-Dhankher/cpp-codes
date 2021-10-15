

// } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n) {

    int localmax = 0, globalmax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        localmax = max(arr[i], arr[i] + localmax);
        if (globalmax < localmax)
            globalmax = localmax;
    }
    return globalmax;

}

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t; //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends