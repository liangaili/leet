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
    vector<int> sorted;
    void travel(TreeNode *root) {
        if (root==NULL) {
            return;
        }
        if (root->left!=NULL) {
            travel(root->left);
        }
        sorted.push_back(root->val);
        if (root->right!=NULL) {
            travel(root->right);
        }
        return;
    }
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sorted.clear();
        travel(root);
        if (sorted.size()<=1) {
            return true;
        }
        for (int i=0; i<sorted.size()-1;i++) {
            if (sorted[i]>=sorted[i+1]) {
                return false;
            }
        }
        return true;
    }
};