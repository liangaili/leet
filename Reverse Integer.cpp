class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool neg = x<0 ? true : false;
        int ret = 0;
        
        x = abs(x);
        while (x != 0) {
            ret = ret*10 + x%10;
            x/=10;
        }
        
        if (neg) {
            ret = -ret;
        }
        return ret;
    }
};