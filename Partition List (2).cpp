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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return head;
        }

        

        ListNode * lhead = NULL;
        ListNode * ltail = NULL;
        ListNode * rhead = NULL;
        ListNode * rtail = NULL;
        
        if (head->val < x) {
            lhead = head;
            ltail = head;
            
            ListNode * p = head;
            while (p!=NULL && p->val < x) {
                p = p->next;
            }
            if (p==NULL) {
                return head;
            }
            else {
                rhead = p;
                rtail = p;
            }
        }
        else {
            rhead = head;
            rtail = head;
            ListNode * p = head;
            while (p!=NULL && p->val>=x) {
                p=p->next;
            }
            if (p==NULL) {
                return head;
            }
            else {
                lhead = p;
                ltail = p;
            }
        }
        
        
        ListNode * p = head;

        while (p!=NULL) {
            if (p==lhead || p==rhead) {
                p=p->next;
                continue;
            }
            
            if (p->val < x) {
                ltail->next = p;
                ltail = p;
            }
            else {
                rtail->next = p;
                rtail = p;
            }
            p=p->next;
        }

        ltail->next = rhead;
        rtail->next = NULL;
    
        return lhead;
    }
};
