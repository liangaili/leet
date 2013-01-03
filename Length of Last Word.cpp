class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s==NULL) {
            return 0;
        }
        int len = 0;
        int lastlen = 0;
        while (*s != '\0') {
            if (*s==' '){
                if (len>0)
                    lastlen = len;
                len = 0;
            }
            else {
                len++;
            }
            s++;
        }
        if (len>0) {
            return len;
        }
        else{
            return lastlen;
        }
    }
};
