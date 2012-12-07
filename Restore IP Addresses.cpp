class Solution {
private:
    vector<string> ret;
    int atoi(string s){
        int ret = 0;
        for (int i=0; i<s.length(); i++) {
            ret = ret * 10 + s[i] - '0';
        }
        return ret;
    }
    void output(const string & s, vector<int>pos) {
        string cret = s.substr(0, pos[0]);
        cret += ".";
        cret += s.substr(pos[0], pos[1]-pos[0]);
        cret += ".";
        cret += s.substr(pos[1], pos[2]-pos[1]);
        cret += ".";
        cret += s.substr(pos[2], s.length()-pos[2]);
        ret.push_back(cret);
    }
    void recurive(const string &s, vector<int>pos) {
        if (pos.size()==3) {
            if (pos[2]>=s.length()) {
                return;
            }
            string x = s.substr(pos[2], s.length()-pos[2]);
            if (x.length()>1 && x[0]=='0') {
                return;
            }
            int num = atoi(x);
            if (num>=0 && num<=255) {
                output(s, pos);
            }
        }
        for (int i=1; i<4; i++) {
            
            int begin=0;
            if (pos.size()>0) {
                begin = pos[pos.size()-1];
            }
            if (begin>=s.length()) {
                return;
            }
            if (i>1 && s[begin]=='0'){
                return;
            }
            string x = s.substr(begin, i);
            
            int num = atoi(x);
            pos.push_back(0);
            if (num>=0 && num<=255) {
                pos[pos.size()-1] = begin+i;
                recurive(s, pos);
            }
            pos.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        vector<int> pos;
        pos.clear();
        
        if (s.length()>12){
            return ret;
        }
        
        recurive(s, pos);
        return ret;
    }
};