/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode x = ListNode(0);
        ListNode *p = &x;
        p->next = head;
        ListNode * prev = p;
        
        ListNode * q = head;
        while(q != NULL && q->next != NULL) {
            if (q->val == q->next->val) {
                int val = q->val;
                while (q!=NULL && q->val == val) {
                    q=q->next;
                }
            }
            else {
                prev->next = q;
                prev = q;
                q=q->next;
            }
        }
        prev->next = q;
        return p->next;
    }
};
