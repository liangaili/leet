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
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root==NULL) {
            return 0;
        }
        if (root->left==NULL && root->right==NULL) {
            return 1;
        }
        else {
            int depleft = maxDepth(root->left);
            int depright = maxDepth(root->right);
            if (root->left == NULL) {
                return depright+1;
            }
            else if (root->right == NULL) {
                return depleft+1;
            }
            else {
                int min = depleft > depright ? depleft : depright;
                return 1 + min;
            }
        }
    }
};