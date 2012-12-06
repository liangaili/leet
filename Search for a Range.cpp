class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> nomatch;
        nomatch.push_back(-1);
        nomatch.push_back(-1);
        if (target<A[0] || A[n-1]<target) {
            return nomatch;
        }
        
        int begin=0;
        int end=n;
        while(begin<end){
            if(A[begin]==target) {
                break;
            }
            if (end-begin==1 && A[begin]!=target) {
                return nomatch;
            }
            int middle = (begin+end+1)/2;
            if (A[middle-1]<target) {
                begin=middle;
            }
            else {
                end=middle;
            }
        }
        vector<int>ret;
        ret.push_back(begin);
        
        begin=0;
        end=n;
        while(begin<end){
            if(A[end-1]==target) {
                break;
            }
            if (end-begin==1 && A[begin]!=target) {
                return nomatch;
            }
            int middle = (begin+end+1)/2;
            if (A[middle]>target) {
                end=middle;
            }
            else {
                begin=middle;
            }
        }
        ret.push_back(end-1);
        return ret;
    }
};