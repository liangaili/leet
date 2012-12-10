class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<char> x;
        vector<int> y;
        x.clear();
        
        int curvalid=0;
        int curpair=0;
        int maxvalid=0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                x.push_back('(');
                y.push_back(i);
            }
            else {
                if (x.size()==0) {
                    curvalid = 0;
                    curpair = 0;
                    x.push_back(')');
                    y.push_back(i);
                }
                else if (x[x.size()-1] == '('){
                    x.pop_back();
                    curpair = y.size()==1? i+1 : i-y[y.size()-2];
                    y.pop_back();
                    if (curpair>maxvalid) {
                        maxvalid = curpair;
                    }
                }
                else {
                    curvalid = 0;
                    curpair = 0;
                    x.push_back(')');
                    y.push_back(i);
                    continue;
                }
            }
        }
        return maxvalid;
    }
};