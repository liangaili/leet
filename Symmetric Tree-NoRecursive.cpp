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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }
        vector<TreeNode *> v;
        v.clear();
        v.push_back(root->left);
        v.push_back(root->right);
        
        while(v.size()!=0) {
            for (int i=0; i<v.size()/2; i++) {
                TreeNode * left = v[i];
                TreeNode * right = v[v.size()-1-i];
                if (left==NULL && right==NULL) {
                    continue;
                }
                if (left==NULL || right==NULL) {
                    return false;
                }
                if (left->val != right->val) {
                    return false;
                }
            }
            vector<TreeNode *> tmp;
            tmp.clear();
            for (int i=0;i<v.size();i++){
                if (v[i]==NULL) {
                    continue;
                }
                tmp.push_back(v[i]->left);
                tmp.push_back(v[i]->right);
            }
            v = tmp;
        }
        return true;
    }
};