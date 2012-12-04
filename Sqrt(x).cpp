class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x<=1) {
            return x;
        }
        unsigned long y = x;
        unsigned long big=1;
        
        while (big<50000 && big * big <= y) {
            big = big*2;
        }
        
        unsigned int small = big/2;
        while (big-small>1) {
            int middle=(big+small)/2;
            if (middle*middle>y) {
                big=middle;
            }
            else {
                small=middle;
            }
        }
        return small;
    }
};