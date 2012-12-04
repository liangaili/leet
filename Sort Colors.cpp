class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int head = 0;
        int whead = 0;
        
        int tail = n-1;
        int wtail = n-1;

        while (head<=tail) {
            int c=A[head];
            A[head]=1;
            if (c==0) {
                A[whead] = 0;
                whead++;
                head++;
                continue;
            }
            if (c==1) {
                
                head++;
                continue;
            }
            if (c==2) {
                A[head]=A[tail];
                A[tail]=2;
            }
            if (A[tail]==2) {
                A[wtail] = 2;
                wtail--;
                tail--;
                continue;
            }
            if (A[tail]==1) {
                tail--;
                continue;
            }
        }
    }
};