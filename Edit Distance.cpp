class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > M = vector<vector<int> >(word1.length()+1, vector<int>(word2.length()+1, 0));
        M[0][0] = 0;
        for (int i=1; i<=word1.length(); i++) {
            M[i][0] = i;
        }
        for (int j=1; j<=word2.length(); j++) {
            M[0][j] = j;
        }
        for (int i=1; i<=word1.length(); i++) {
            for (int j=1; j<=word2.length(); j++) {
                int ins = M[i-1][j]<M[i][j-1] ? M[i-1][j]+1 : M[i][j-1]+1;
                int add = M[i-1][j-1];
                if (word1[i-1] != word2[j-1]) {
                    add++; 
                }
                M[i][j] = ins < add ? ins : add;
            }
        }
        return M[word1.length()][word2.length()];
    }
};
