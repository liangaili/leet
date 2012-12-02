/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root==NULL) {
            return;
        }
        root->next = NULL;
        while(root->left != NULL) {
          
            TreeLinkNode * p = root;

            while(p!=NULL) {
                p->left->next = p->right;
                if (p->next == NULL) {
                    p->right->next = NULL;
                }
                else {
                    p->right->next = p->next->left;
                }
                p=p->next;
            }
            root = root->left;
        }
        return ;
    }
};