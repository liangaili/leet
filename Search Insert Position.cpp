class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int begin = 0;
        int end = n;
        while(end>begin) {
            if (target<=A[begin]) {
                break;
            }
            if (target>A[end-1]) {
                begin=end;
                break;
            }
            if (target==A[end-1]){
                begin=end-1;
                break;
            }
            int middle = (begin+end+1)/2;
            if (target<A[middle]) {
                end=middle;
            }
            else {
                begin=middle;
            }
        }
        return begin;
    }
};