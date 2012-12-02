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
        ListNode * p = head;
        ListNode * lesshead = NULL;
        ListNode * lesstail = NULL;
        ListNode * morehead = NULL;
        ListNode * moretail = NULL;
        while(p!=NULL) {
            if (p->val<x) {
                if (lesshead == NULL) {
                    lesshead = p;
                }
                if (lesstail!=NULL) {
                    lesstail->next = p;
                }
                lesstail = p;
            }
            else {
                if (morehead == NULL) {
                    morehead = p;
                }
                if (moretail!=NULL) {
                    moretail->next = p;
                }
                moretail = p;
            }
            p=p->next;
        }
        if (lesstail!=NULL)
            lesstail->next = morehead;
        if (moretail!=NULL)
            moretail->next = NULL;
        if (lesshead!=NULL)
            return lesshead;
        else
            return morehead;
    }
};