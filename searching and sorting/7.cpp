class Solution {
public:
    int *findTwoElement(int *arr, int n) {
        for (int i = 0; i < n; i++)
            arr[i] = arr[i] - 1;

        for (int i = 0; i < n; i++)
            arr[arr[i] % n] += n;

        for (int i = 0; i < n; i++)
            arr[i] /= n;

        int *a = new int[2];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                a[1] = i + 1;
            if (arr[i] == 2)
                a[0] = i + 1;
        }

        return a;
    }
};