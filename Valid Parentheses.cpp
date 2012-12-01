class Solution {
private:
    char wife(char husband) {
        switch(husband) {
            case '}':
                return '{';
            case ']':
                return '[';
            case ')':
                return '(';
            default:
                return '\0';
        }
    }
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <char> stack;
        for (int i=0; i<s.length(); i++) {
            if (s[i]=='(' || s[i] == '[' || s[i] == '{') {
                stack.push_back(s[i]);
            }
            else if (s[i]==')' || s[i] == ']' || s[i] == '}'){
                if (stack.size()>0 && stack[stack.size()-1]==wife(s[i])) {
                    stack.pop_back();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return (stack.size()==0);
    }
};