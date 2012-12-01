class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows == 1) {
            return s;
        }
        string c[nRows];
        for (int i=0; i<nRows; i++) {
            c[i] == "";
        }
        int div = nRows*2-2;
        for (int i=0; i<s.length(); i++) {
            int x = i % div;
            if (x<=div/2) {
                c[x]+=s[i];
            }
            else {
                c[div-x] += s[i];
            }
        }
        
        string ret = "";
        for (int i=0; i<nRows; i++) {
            ret+=c[i];
        }
        return ret;
    }
};