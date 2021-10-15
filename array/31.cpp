class Solution {
public:
    void threeWayPartition(vector<int>& array, int a, int b)
    {
        int left = 0;
        int right = array.size() - 1;
        int mid = 0;
        while (mid <= right)
        {
            if (array[mid] < a)
                swap(array[left++], array[mid++]);
            else if (array[mid] >= a && array[mid] <= b)
                mid++;
            else if (array[mid] > b)
                swap(array[mid], array[right--]);
        }
    }
};