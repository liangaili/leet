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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL) {
            return head;
        }
        ListNode * tmp = head;
        ListNode * last = NULL;
        int length = 0;
        while(tmp!=NULL) {
            length++;
            last = tmp;
            tmp=tmp->next;
        }
        int r = k%length;
        if (r==0) {
            return head;
        }
        
        tmp = head;
        for(int i=0; i<r; i++) {
            tmp=tmp->next;
        }
        ListNode * ntail=head;
        while(tmp->next!=NULL) {
            tmp=tmp->next;
            ntail=ntail->next;
        }
        ListNode * nhead = ntail->next;
        last->next = head;
        ntail->next=NULL;
        return nhead;
        
    }
};