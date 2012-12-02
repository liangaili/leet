class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<=1) {
            return n;
        }
        
        int prev = A[0];
        int write = 1;
        for (int i=1; i<n; i++) {
            if (A[i]!=prev || write<=1 ||  (write>1 && A[write-1]!=A[write-2])) {
                A[write] = A[i];
                prev = A[i];
                write++;
            }
        }
        return write;
        
    }
};        
