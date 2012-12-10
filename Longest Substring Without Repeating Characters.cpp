class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hash[26];
        for (int i=0; i<26; i++) {
            hash[i] = -1;
        }
        int curlen = 0;
        int maxlen = 0;
        int laststart = 0;
        for (int i=0; i<s.length(); i++) {
            if (hash[s[i]-'a']+1 > laststart) {
                laststart = hash[s[i]-'a']+1;
            }
            
            curlen = i-laststart+1;
            if (curlen>maxlen) {
                maxlen = curlen;
            }
            hash[s[i] - 'a'] = i;
        }
        return maxlen;
    }
};