class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0) {
            return 0;
        }
        int ret = A[0];
        int curr = A[0];
        for (int i=1; i<n; i++) {
            if (curr<0) {
                curr = A[i];
            }
            else {
                curr += A[i];
            }
            if (curr>ret) {
                ret = curr;
            }
        }
        return ret;
    }
};