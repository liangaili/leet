/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<int> > ret;
    void path(TreeNode *root, int sum, vector<int> x) {
        if (root==NULL) {
            return;
        }
        if (root->left==NULL && root->right==NULL && sum==root->val) {
            x.push_back(root->val);
            ret.push_back(x);
            return;
        }
        vector<int>t = x;
        t.push_back(root->val);
        if (root->left!=NULL) {
            path(root->left, sum-root->val, t);
        }
        if (root->right!=NULL) {
            path(root->right, sum-root->val, t);
        }
        return;
        
        
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> t;
        ret.clear();
        path(root, sum, t);
        return ret;
    }
};