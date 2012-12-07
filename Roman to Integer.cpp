class Solution {
private:
    int getInt(char c) {
        switch(c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int last = 0;
        int ret = 0;
        for (int i=s.length()-1; i>=0; i--) {
            int curr = getInt(s[i]);
            if (curr>=last) {
                ret+=curr;
            }
            else {
                ret-=curr;
            }
            last=curr;
        }
        return ret;
    }
};