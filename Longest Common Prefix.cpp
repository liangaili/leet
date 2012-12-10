class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size() == 0) {return "";}
        string ret = "";
        int j=0;
        while (true) {

            char x = '\0';
            for (int i=0; i<strs.size(); i++) {
                if (strs[i].length() <= j) {
                    return ret;
                }
                if (x=='\0') {
                    x = strs[i][j];
                }
                else {
                    if (x!=strs[i][j]) {
                        x = '\0';
                        break;
                    }
                }
            }
            if (x!='\0'){
                ret = ret + x;
                j++;
            }
            else {
                break;
            }
                
        }
        return ret;
    }
};