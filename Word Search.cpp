class Solution {
private:
    bool travel(vector<vector<char> >&board, vector<vector<char> >& used, int i, int j, string word, int index) {
        if (index == word.length()) {
            return true;
        }
        if (i-1>=0 && used[i-1][j] == 0 && board[i-1][j] == word[index]) {
            used[i-1][j] = 1;
            if (travel(board, used, i-1, j, word, index+1) == true) {
                return true;
            }
            used[i-1][j] = 0;
        }
        if (j-1>=0 && used[i][j-1] == 0 && board[i][j-1] == word[index]) {
            used[i][j-1] = 1;
            if (travel(board, used, i, j-1, word, index+1) == true) {
                return true;
            }
            used[i][j-1] = 0;
        }
        if (i+1<board.size() && used[i+1][j] == 0 && board[i+1][j] == word[index]) {
            used[i+1][j] = 1;
            if (travel(board, used, i+1, j, word, index+1) == true) {
                return true;
            }
            used[i+1][j] = 0;
        }
        if (j+1<board[0].size() && used[i][j+1] == 0 && board[i][j+1] == word[index]) {
            used[i][j+1] = 1;
            if (travel(board, used, i, j+1, word, index+1) == true) {
                return true;
            }
            used[i][j+1] = 0;
        }
        return false;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.length() == 0) {
            return true;
        }
        if (board.size()==0) {
            return false;
        }
        if (board[0].size()==0) {
            return false;
        }
        vector<vector<char> > used = board;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                used[i][j]=0;
            }
        }
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    used[i][j] = 1;
                    if (travel(board, used, i, j, word, 1)==true) {
                       return true;
                    }
                    used[i][j] = 0;
                }
            }
        }
        return false;
    }
};