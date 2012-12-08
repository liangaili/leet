class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int write = m+n-1;
        int r1 = m-1;
        int r2 = n-1;
        while (r1>=0 && r2>=0) {
            if (A[r1] < B[r2]) {
                A[write] = B[r2];
                r2--;
            }
            else {
                A[write] = A[r1];
                r1--;
            }
            write--;
        }
        while (r2>=0) {
            A[write] = B[r2];
            r2--;
            write--;
        }
        return;
    }
};