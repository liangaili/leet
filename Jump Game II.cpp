class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<=1) {
            return 0;
        }
        int B[n];
        B[n-1] = 0;
        for (int i=n-2; i>=0; i--) {
            int min = n-1-i;
            int lenJump = A[i];
            for (int j=i+1; j<=lenJump+i && j<n; j++) {
                if (B[j]+1 < min) {
                    min = B[j] + 1;
                }
            }
            B[i] = min;
        }
        return B[0];
    }
};
