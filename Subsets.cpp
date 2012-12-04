class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = pow(2, S.size());
        int L = S.size();
        vector<vector<int> > ret;
        sort(S.begin(), S.end());
        for (int i=0; i<N; i++) {
            int c = i;
            vector<int> tmp;
            for (int j=0; j<L; j++) {
                if (c & 1) {
                    tmp.push_back(S[j]);
                }
                c= c>>1;
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};