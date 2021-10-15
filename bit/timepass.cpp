
class Solution {
public:
    int search(int A[], int l, int h, int key) {
        int first = A[0];
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            int value = A[mid];
            if (value == key)
                return mid;

            bool am_big = value >= first;
            bool key_big = key >= first;
            if (am_big == key_big)
            {
                if (value > key)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (am_big)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }


        return -1;
    }
}