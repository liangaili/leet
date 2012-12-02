class Solution {
private:
    void findReplace(vector<int> &num, int &x, int &y) {
        x=-1;
        y=-1;
        int n=num.size()-1;
        while (n>=1 && num[n]<=num[n-1]) {
            n--;
        }
        if (n==0) {
            return;
        }
        x = n-1;
        for (y=num.size()-1; y>x; y--) {
            if (num[y]>num[x]) {
                break;
            }
        }
        return;
    }
    void swap(vector<int> &num, int x, int y) {
        int tmp = num[x];
        num[x] = num[y];
        num[y] = tmp;
    }
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size()==1) {
            return;
        }
        int x, y;
        findReplace( num, x, y);
        if (x==-1 && y==-1) {
            swap(num, 0, num.size()-1);
            
        }
        else {
            swap(num, x, y);
        }
        sort(num.begin()+x+1, num.end());
    }
};