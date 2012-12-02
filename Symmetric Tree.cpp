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
    bool isMirror(TreeNode * left, TreeNode * right) {
        if (left==NULL && right==NULL) {
            return true;
        }
        if (left==NULL || right==NULL) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return isMirror(left->right, right->left) && isMirror(left->left, right->right);
    }
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root==NULL) {
            return true;
        }
        else {
            return isMirror(root->left, root->right);
        }
    }
};