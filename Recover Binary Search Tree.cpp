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
    TreeNode *wrong[2];
    int index;
    TreeNode * prev;
    void push(TreeNode * root) {
        if (index>0) {
            if (prev->val > root->val && wrong[0] == NULL) {
                wrong[0] = prev;
            }
            if (prev->val > root->val) {
                wrong[1] = root;
            }
        }
        prev = root;
        index++;
    }
    void travel(TreeNode *root) {
        if (root==NULL)
            return;
        travel(root->left);
        push(root);
        travel(root->right);
    }
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        index = 0;
        wrong[0] = NULL;
        wrong[1] = NULL;
        travel(root);
        int tmp = wrong[0]->val;
        wrong[0]->val = wrong[1]->val;
        wrong[1]->val = tmp;
    }
};