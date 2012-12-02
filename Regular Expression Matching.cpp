class Solution {
private:
    bool match_single(const char *s, const char *p) {
        if (*s=='\0' && *p=='\0') {
            return true;
        }
        if (*s=='\0' || *p=='\0') {
            return false;
        }
        if(*p=='.'){
            return true;
        }
        return (*s==*p);
    }
    bool isSingle(const char *p) {
        if(*p=='\0') {
            return true;
        }
        if(*(p+1) != '*') {
            return true;
        }
        return false;
    }
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        while(true) {
            if (*s=='\0' && *p=='\0') {
                return true;
            }
            if (isSingle(p)) {
                if (!match_single(s, p)) {
                    return false;
                }
                s++;
                p++;
            }
            else {
                if (isMatch(s, p+2)) {
                    return true;
                }
                while(match_single(s, p)){
                    if (isMatch(s+1, p+2)) {
                        return true;
                    }
                    s++;
                }
                return false;
            }
        }
    }
};