class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0) {
            return 1;
        }
        if (x==1 || x==0) {
            return x;
        }
        bool minus = n<0;
        if (n<0) {
            n=-n;
        }
        double curr=x;
        double ret = 1;
        int bit = 1;
        
        while(bit != 0) {
            if ((bit & n) !=0) {
                ret = ret * curr;
            }
            curr = curr * curr;
            bit = bit << 1;
        }
        if (minus) {
            return 1/ret;
        }
        else {
            return ret;
        }
    }
};
