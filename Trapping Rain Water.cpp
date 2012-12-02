class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int all = 0;
        int start = 0;
        int end = n-1;
        int prev = 0;
        while (start <= end && start<n && end>=0) {
            
            int x = A[start];
            int y = A[end];
            if (x<y) {
                all += (x-prev)*(end-start+1);
                prev = x;
                while (A[start]<=x)
                    start++;
            }
            else if (x>y) {
                
                all += (y-prev)*(end-start+1);
                prev = y;
                while (A[end]<=y)
                    end--;
            }
            else {
                all += (x-prev)*(end-start+1);
                prev = x;
                //return all;
                while (A[start]<=x)
                    start++;
                while (A[end]<=y)
                    end--;
            }
        }
        int stones = 0;
        for (int i=0;i<n;i++) {
            stones += A[i];
        }
        
        return all-stones;
    }
};