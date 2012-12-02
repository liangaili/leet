class Solution {
private:
    vector<vector<int> > p;
    void r(vector<int> &t, vector<int> &num) {
        if (num.size()==0) {
            p.push_back(t);
            return;
        }
        for (int i=0; i<num.size(); i++) {
            vector<int>k = t;
            k.push_back(num[i]);
            vector<int>m = num;
            for (int j=i; j<num.size()-1; j++) {
                m[j] = m[j+1];
            }
            m.pop_back();
            r(k, m);
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        p.clear();
        vector<int> t;
        r(t, num);
        return p;
    }
};