class Solution {
public:

    // Function to find maximum product subarray
    long long maxProduct(int *arr, int n) {
        long long maxvalue = arr[0];
        long long  minvalue = arr[0];
        long long maxproduct = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0)
                swap(maxvalue, minvalue);

            maxvalue = arr[i] > arr[i] * maxvalue ? arr[i] : arr[i] * maxvalue;
            minvalue = arr[i] > arr[i] * minvalue ? arr[i] * minvalue : arr[i];

            maxproduct = max(maxvalue, maxproduct);
        }
        return maxproduct;
    }
};