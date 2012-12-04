class Solution {
private:
    vector<vector<int> > ret;
    void recursive(vector<int> &S, vector<int> & t, int n) {
        if (n>=S.size()) {
            ret.push_back(t);
            return;
        }
        
        t.push_back(S[n]);
        
        recursive(S,t,n+1);
        t.pop_back();
        
        while(n+1<S.size() && S[n]==S[n+1]) {
            n++;
        }
        recursive(S,t,n+1);
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        sort(S.begin(), S.end());
        vector<int> tmp;
        tmp.clear();
        
        recursive(S, tmp, 0);
        return ret;        
    }
};