class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int begin = 0;
        int end = n;
        while (begin<end-1) {
            int middle = (begin+end+1)/2;
            
            int sbegin;
            int send;
            int cbegin;
            int cend;
            if (A[begin]<A[middle-1]) {
                sbegin = begin;
                send = middle;
                cbegin=middle;
                cend=end;
            }
            else {
                sbegin=middle;
                send = end;
                cbegin=begin;
                cend = middle;
            }
            if (target>=A[sbegin] && target<=A[send-1]) {
                begin=sbegin;
                end = send;
            }
            else {
                begin=cbegin;
                end = cend;
            }
        }
        return A[begin]==target?begin:-1;
    }
};