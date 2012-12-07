class Solution {
private: 
    bool simple(string s1, string s2) {
        int A[26];
        int B[26];
        for(int i=0;i<26;i++){
            A[i]=0;
            B[i]=0;
        }
        for (int i=0;i<s1.length();i++){
            A[s1[i]-'a']++;
        }
        for (int i=0;i<s2.length();i++){
            B[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if (A[i]!=B[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.length()==1 && s2.length()==1){
            return s1==s2;
        }
        if (s1==s2){
            return true;
        }
        // simple judge, to save time, avoid useless recrusive
        if (simple(s1,s2)==false){
            return false;
        }
        
        string s1left;
        string s1right;
        
        string s2left;
        string s2right;
        
        for(int i=1; i<=s1.length()-1; i++) {
            int left = i;
            int right = s1.length()-i;
            
            s1left = s1.substr(0, left);
            s1right = s1.substr(left, right);
            
            s2left = s2.substr(0, left);
            s2right = s2.substr(left, right);
            if (isScramble(s1left, s2left) && isScramble(s1right, s2right)) {
                return true;
            }
            
            s1left = s1.substr(0, left);
            s1right = s1.substr(left, right);
            
            s2left = s2.substr(0, right);
            s2right = s2.substr(right, left);
            if (isScramble(s1left, s2right) && isScramble(s1right, s2left)) {
                return true;
            }
            
            s1left = s1.substr(0, right);
            s1right = s1.substr(right, left);
            
            s2left = s2.substr(0, left);
            s2right = s2.substr(left, right);
            if (isScramble(s1left, s2right) && isScramble(s1right, s2left)) {
                return true;
            }
            
            s1left = s1.substr(0, right);
            s1right = s1.substr(right, left);
            
            s2left = s2.substr(0, right);
            s2right = s2.substr(right, left);
            if (isScramble(s1left, s2left) && isScramble(s1right, s2right)) {
                return true;
            }
        }
        return false;
    }
};