class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (numRows <= 0) {
            return ret;
        }
        vector<int> line = vector<int>(1,1);
        ret.push_back(line);
        for (int i=1; i<numRows; i++) {
            vector<int> curr;
            curr.push_back(1);
            for (int j=1; j<i; j++) {
                curr.push_back(ret[i-1][j-1] + ret[i-1][j]);
            }
            curr.push_back(1);
            ret.push_back(curr);
        }
        return ret;
    }
};
