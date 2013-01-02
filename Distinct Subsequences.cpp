class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S=="" | T=="") {
            return 0;
        }
        if (S.length()<T.length()) {
            return 0;
        }
        vector<vector<int> > M = vector<vector<int> >(T.length()+1, vector<int>(S.length()+1, 0));

        for (int i=0; i<T.length(); i++) {
            if (T[i] == S[i]) {
                M[i][i] = 1;
            }
            else {
                break;
            }
        }       
        
        for (int i=1; i<S.length(); i++) {
            if (T[0] == S[i]) {
                M[0][i] = M[0][i-1] + 1;
            }
            else {
                M[0][i] = M[0][i-1];
            }
        }
        
        for (int i=1; i<T.length(); i++) {
            for (int j=i+1; j<S.length(); j++) {
                if (T[i] == S[j]) {
                    M[i][j] = M[i][j-1] + M[i-1][j-1];
                }
                else {
                    M[i][j] = M[i][j-1];
                }
            }
        }

        
        return M[T.length() - 1][S.length() - 1];
    }
};
