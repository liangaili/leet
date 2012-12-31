class Solution {
private:
    vector <string> ret;
    vector <string> letters;
    void init() {
        letters.push_back(" ");
        letters.push_back("");
        letters.push_back("abc");
        letters.push_back("def");
        letters.push_back("ghi");
        
        letters.push_back("jkl");
        letters.push_back("mno");
        letters.push_back("pqrs");
        letters.push_back("tuv");
        letters.push_back("wxyz");
    }
    
    void recursive(string curr, string digits) {
        if (digits.length()==0) {
            ret.push_back(curr);
            return;
        }
        string remain = digits.substr(1);
        char curr_letter = digits[0];
        if (curr_letter<'0' || curr_letter >'9' ) {
            recursive(curr, remain);
        }
        for (int i=0; i<letters[curr_letter-'0'].length(); i++) {
            recursive(curr+letters[curr_letter - '0'][i], remain);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        letters.clear();
        init();
        recursive("", digits);
        return ret;
    }
};
