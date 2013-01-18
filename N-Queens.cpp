class Solution {
private:
    int N;
    vector<vector<string> > ret;
    bool placeable(int line, int *x) {
        for (int i=0; i<line; i++) {
            if (x[line]==x[i] || abs(line-i)==abs(x[line]-x[i])) {
                return false;
            }
        }
        return true;
    }
    void output(int *x) {
        vector<string> ss;
        for (int i=0; i<N; i++) {
            string s="";
            for (int j=0; j<N; j++) {
                if (j==x[i]) {
                    s=s+'Q';
                }
                else {
                    s=s+'.';
                }
            }
            ss.push_back(s);
        }
        ret.push_back(ss);
    }
    void recursive(int line, int *x) {
        if (line==N) {
            output(x);
            return;
        }
        for (int i=0; i<N; i++) {
            x[line] = i;
            if (placeable(line, x)) {
                recursive(line+1, x);
            }
        }
        
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* x = new int[n];
        N=n;
        ret.clear();
        recursive(0, x);
        delete[] x;
        return ret;
    }
};
