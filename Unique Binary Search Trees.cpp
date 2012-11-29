class Solution {
private:
    vector<int> A;
    int num(int n) {
        int ret = 0;
        if (n<=1) {
            ret = 1;
        }
        else {
            for (int i=0; i<n; i++) {
                ret += num(i)*num(n-1-i);
            }
        }
        if (A[n] == 0){
            A[n] = ret;
        }
        return ret;
    }
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        for (int i=0; i<n+1; i++) {
            A.push_back(0);
        }
        return num(n);

    }
};
