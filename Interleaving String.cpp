class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1+len2 != s3.length()) {
            return false;
        }
        vector<vector<bool> > match(len1+1, vector<bool>(len2+1, false));
        match[0][0] = true;
        for (int i=0; i<len1; i++) {
            if (s1[i] == s3[i]) {
                match[i+1][0] = true;
            }
            else {
                break;
            }
        }
        for (int i=0; i<len2; i++) {
            if (s2[i] == s3[i]) {
                match[0][i+1] = true;
            }
            else {
                break;
            }
        }
        for (int i=1; i<=len1; i++) {
            for (int j=1; j<=len2; j++) {
                bool r = false;
                char c = s3[i+j-1];
                if (match[i-1][j] == true) {
                    r = r | (c==s1[i-1]);
                }
                if (match[i][j-1] == true) {
                    r = r | (c==s2[j-1]);
                }
                match[i][j] = r;
            }
        }
        return match[len1][len2];
    }
};
