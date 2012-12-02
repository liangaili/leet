class Solution {
private:
string find(vector<vector<char> > &board, int x, int y){
    string ret = "";
    int a[9] = {1,1,1,1,1,1,1,1,1};
    int b[9] = {1,1,1,1,1,1,1,1,1};
    for (int i=0; i<9; i++) {
        if (i==y)
            continue;
        if (board[x][i]!='.') {
            a[board[x][i]-'1'] =0;
            b[board[x][i]-'1'] --;
        }
    }
    for (int i=0; i<9; i++) {
        if (b[i]<0) {
            return "";
        }
        b[i] = 1;
    }
    
    for (int i=0; i<9; i++) {
        if (i==x)
            continue;
        if (board[i][y]!='.') {
            a[board[i][y]-'1'] =0;
            b[board[i][y]-'1'] --;
        }
    }
    for (int i=0; i<9; i++) {
        if (b[i]<0) {
            return "";
        }
        b[i] = 1;
    }
    
    int sx = (x/3) * 3;
    int sy = (y/3) * 3;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int cx = sx+i;
            int cy = sy+j;
            if (cx==x && cy==y) {
                continue;
            }
            if (board[cx][cy]!='.') {
                a[board[cx][cy]-'1'] =0;
                b[board[cx][cy]-'1'] --;
            }
        }
    }
    for (int i=0; i<9; i++) {
        if (b[i]<0) {
            return "";
        }
        b[i] = 1;
    }
    
    for (int i=0; i<9; i++) {
        if (a[i]==1) {
            ret+='1'+i;
        }
    }
    return ret;
}


public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j]=='.' and find(board, i, j)=="") {
                    return false;
                }
            }
        }
        return true;
    }
};