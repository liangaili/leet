class Solution {
private:
    int per(int n) {
        if (n<=1) {
            return 1;
        }
        else{
            return n*per(n-1);
        }
    }
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        k--;
        
        vector<int> nums;
        int pers = per(n);
        for (int i=0; i<n; i++) {
            nums.push_back(i);
        }
        vector<int> ret;

        while(nums.size()>0) {
            pers = pers/nums.size();
            int index = k/pers;
            k = k%pers;
            ret.push_back(nums[index]);
            for (int j=index; j< nums.size()-1; j++) {
                nums[j] = nums[j+1];
            }
            nums.pop_back();
        }
        string retstr;
        for (int i=0; i<ret.size(); i++) {
            retstr += '1' + ret[i];
        }
        return retstr;
    }
};