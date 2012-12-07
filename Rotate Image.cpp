class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=matrix.size();
        for (int i=0; i<n/2; i++) {
            for (int j=0; j<(n+1)/2; j++) {
                int x=i;
                int y=j;
                int last;
                for (int k=0; k<3; k++) {
                    int newy=x;
                    int newx=n-1-y;
                    
                    // not effective enough
                    last = matrix[newx][newy];
                    matrix[newx][newy] = matrix[x][y];
                    matrix[x][y] = last;
                    
                    x=newx;
                    y=newy;
                }
            }
        }
    }
};