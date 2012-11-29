class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> x;
        for (int i=0; i<target+1; i++) {
            x.push_back(-1);
        }
        vector <int> ret;
        ret.push_back(0);
        ret.push_back(0);
        for (int i=0 ; i<numbers.size(); i++) {
            if (numbers[i]<0)
                continue;
            if (numbers[i]>target) {
                continue;
            }
            if (x[target - numbers[i]] != -1)  {
                ret[0] = x[target - numbers[i]]+1;
                ret[1] = i+1;
                return ret;
            }
            x[numbers[i]] = i;
        }
        return ret;
    }
};