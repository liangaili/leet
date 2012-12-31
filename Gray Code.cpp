class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(1<<n);
        ret[0]=0;
        int len = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<len; j++) {
                ret[j+len] = ret[len-1-j] + len;
            }
            len = len+len;
        }
        return ret;
    }
};
