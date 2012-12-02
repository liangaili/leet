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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL || head->next==NULL) {
            return head;
        }
        ListNode * nhead = head->next;
        
        ListNode * curr = head;
        ListNode * last = NULL;
        while(curr!=NULL && curr->next!=NULL) {
            ListNode * tmp = curr->next->next;
            if (last!=NULL) {
                last->next=curr->next;
            }
            curr->next->next = curr;
            last=curr;
            curr=tmp;
        }
        if (last != NULL) {
            last->next = curr;
        }
        
        return nhead;
    }
};