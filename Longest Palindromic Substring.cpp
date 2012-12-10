class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N=s.length();
        string t = s;
        
        int x[N][N];
        for (int i=0; i<N; i++) {
            t[i] = s[N-1-i];
            for (int j=0; j<N; j++) {
                x[i][j] = 0;
            }
        }
        int pos = -1;
        int max = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == t[0]) {
                x[0][i] = 1;
                pos = i;
                max = 1;
            }
            if (s[0] == t[i]) {
                x[i][0] = 1;
                pos = 0;
                max = 1;
            }
        }
        for (int i=1; i<N; i++) {
            for (int j=1; j<N; j++) {
                if (t[i] == s[j]) {
                    x[i][j] = x[i-1][j-1] + 1;
                    if (x[i][j]>max) {
                        max = x[i][j];
                        pos = j;
                    }
                }
                else {
                    x[i][j] = 0;
                }
            }
        }

        return s.substr(pos+1-max, max);
        
    }
};