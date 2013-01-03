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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode x(0);
        ListNode * q = &x;
        ListNode * p = &x;
        q->next = head;
        p->next = head;
        for (int i=0; i<n; i++) {
            q = q->next;
        }
        while(q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        if (p->next==head) {
            head=p->next->next;
        }
        p->next = p->next->next;
        
        return head;

    }
};
