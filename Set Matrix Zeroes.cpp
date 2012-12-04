class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // mark first line contains 0;
        int h=1;
        for (int i=1; i<matrix.size(); i++) {
            if (matrix[i][0]==0) {
                h=0;
            }
        }
        
        // mark first row contains 0
        int v=1;
        for (int j=1; j<matrix[0].size(); j++) {
            if (matrix[0][j]==0) {
                v = 0;
            }
        }
        
        
        for (int i=1; i<matrix.size(); i++) {
            for (int j=1; j<matrix[i].size(); j++) {
                if (matrix[i][j]==0) {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        for (int i=1; i<matrix.size(); i++) {
            if (matrix[i][0] != 0){
                continue;
            }
            for (int j=0; j<matrix[i].size(); j++) {
                matrix[i][j] = 0;
            }
        }
        
        for (int j=1; j<matrix[0].size(); j++) {
            if (matrix[0][j] != 0){
                continue;
            }
            for (int i=0; i<matrix.size(); i++) {
                matrix[i][j] = 0;
            }
        }
        
        // 0-ize first line
        if (h==0 || matrix[0][0] ==0) {
            for (int i=1; i<matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
        
        // 0-ize first row
        if (v==0 || matrix[0][0] ==0) {
            for (int j=1; j<matrix[0].size(); j++) {
                matrix[0][j]=0;
            }
        }
        
        // 0-ize cornor
        if (h==0 || v==0) {
            matrix[0][0] = 0;
        }
    }
};