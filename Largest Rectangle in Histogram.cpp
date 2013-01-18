class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.size() <= 0) {
            return 0;
        }
        
        vector<int> stack;
        vector<int> left;
        int max=0;
        //stack.push_back(height[0]);
        //left.push_back(1);
        for (int i=0; i<=height.size(); i++) {
            int h;
            if (i<height.size()) {
                h = height[i];
            }
            else {
                h = 0;
            }
            if (stack.size()==0 || h>stack.back()) {
                stack.push_back(h);
                left.push_back(1);
            }
            else {
                int cnt = 1;
                while (stack.size()>0 && stack.back()>h) {
                    int currh = stack.back();
                    int currl = left.back();
                    stack.pop_back();
                    left.pop_back();
                    
                    int curr = (cnt+currl-1) * currh;
                    if (curr>max) {
                        max = curr;
                    }
                    cnt+=currl;
                }
                stack.push_back(h);
                left.push_back(cnt);
            }
        }

        return max;
    }
};
