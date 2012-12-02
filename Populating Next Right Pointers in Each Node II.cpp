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
        while(root != NULL) {
            TreeLinkNode * p = NULL;
            TreeLinkNode * head = NULL;
            TreeLinkNode * prev = NULL;
            while(root!=NULL) {
                if (root->left != NULL) {
                    p=root->left;
                    if (head == NULL) {
                        head = p;
                    }
                    if (prev != NULL) {
                        prev->next = p;
                    }
                    prev = p;
                }
                if (root->right != NULL) {
                    p=root->right;
                    if (head == NULL) {
                        head = p;
                    }
                    if (prev != NULL) {
                        prev->next = p;
                    }
                    prev = p;
                }
                root=root->next;
            }
            if (prev!=NULL) {
                prev->next = NULL;
            }
            root = head;
        }
        return ;        
    }
};