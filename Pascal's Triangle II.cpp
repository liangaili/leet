class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> x;
        for (int i=0; i<rowIndex+1; i++) {
            x.push_back(0);
        }
        x[0] = 1;
        for (int i=0; i<rowIndex; i++) {
            for (int j=i+1;j>=1; j--) {
                x[j] += x[j-1];
            }
        }
        return x;
    }
};