class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num1 =="" || num2=="" || num1=="0" || num2=="0") {
            return "0";
        }
        
        int N=num1.length()+num2.length();
        int digits[N];
        for (int i=0; i<N; i++) {
            digits[i] = 0;
        }
        
        for (int i=0; i<num1.length(); i++) {
            for (int j=0; j<num2.length(); j++) {
                digits[i+j] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
        string ret = "";
        for (int i=N-2; i>0; i--) {
            char c = '0' + digits[i]%10;
            ret = c + ret;
            digits[i-1] += digits[i]/10;
        }
        while (digits[0] != 0) {
            char c = '0' + digits[0]%10;
            ret = c + ret;
            digits[0] = digits[0]/10;
        }
        return ret;
    }
};