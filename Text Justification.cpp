class Solution {
    int find_end(vector<string> &words, int start, int L) {
        int len=words[start].length();
        int end = start+1;
        while (end<words.size()) {
            len ++;
            len +=words[end].length();
            if (len>L) {
                break;
            }
            end++;
        }
        return end;
    }
    string justify(vector<string> &words, int start, int end, int L) {
        int clen = 0;
        for(int i=start; i<end; i++) {
            clen = clen + words[i].length();
        }
        int slen = L - clen;
        if (end-start == 1) {
            string s = words[start];
            for (int i=0; i<slen; i++) {
                s+=' ';
            }
            return s;
        }
        else if(end!=words.size()) {
            int average = slen/(end-start-1);
            int more = slen - (end-start-1)*average;
            string s = words[start];
            for (int i=start+1;i<end;i++){
                int loop = average;
                if (i-start<more+1) {
                    loop = average+1;
                }
                for (int j=0; j<loop; j++) {
                    s+=' ';
                }
                s+=words[i];
            }
            return s;
        }
        else {
            string s = words[start];
            for (int i=start+1; i<end; i++) {
                s+=' ';
                s+=words[i];
            }
            int len = s.length();
            for (int i=0; i<L-len; i++) {
                s+=' ';
            }
            return s;
        }
    }
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        int start = 0;
        while (start<words.size()) {
            int end = find_end(words, start, L);
            string s = justify(words, start, end, L);
            ret.push_back(s);
            start = end;
        }
        return ret;
    }
};