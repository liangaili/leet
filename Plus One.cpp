class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        int i=0;
        for (i= digits.size()-1; i>=0; i--){
            if (digits[i] != 9){
                break;
            }
        }
        if (i==-1) {
            ret.push_back(1);
            for (i=0; i<digits.size(); i++) {
                ret.push_back(0);
            }
        }
        else {
            ret = digits;
            ret[i]++;
            for (i=i+1;i<ret.size();i++) {
                ret[i] = 0;
            }
        }
        return ret;
    }
};