class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int begin=0;
        int end=matrix.size()*matrix[0].size();
        
        int div=matrix[0].size();
        while(begin<end-1){
            int middle=(begin+end+1)/2;
            
            if (matrix[(middle-1)/div][(middle-1)%div] < target) {
                begin=middle;
            }
            else {
                end=middle;
            }
        }
        if(matrix[begin/div][begin%div]==target) {
            return true;
        }
        else {
            return false;
        }
    }
};