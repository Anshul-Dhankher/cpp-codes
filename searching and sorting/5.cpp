class Solution {
public:
    int middle(int A, int B, int C) {
        //code here//Position this line where user code will be pasted.
        int Min = min(A, min(B, C));
        int Max = max(A, max(B, C));

        if (A > Min && A < Max)
            return A;
        if (B > Min && B < Max)
            return B;

        return C;
    }
};