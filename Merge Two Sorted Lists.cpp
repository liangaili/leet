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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1==NULL) {
            return l2;
        }
        if (l2==NULL) {
            return l1;
        }
        ListNode * newhead = l1->val < l2->val? l1 : l2;
        if (l1->val<l2->val) {
            l1 = l1->next;
        }
        else {
            l2 = l2->next;
        }
        ListNode * p = newhead;
        while(l1 !=NULL || l2 != NULL) {
            ListNode * tmp = NULL;
            if (l1==NULL) {
                tmp = l2;
                l2 = l2->next;
            }
            else if (l2==NULL) {
                tmp = l1;
                l1 = l1->next;
            }
            else {
                if (l1->val<l2->val) {
                    tmp = l1;
                    l1= l1->next;
                }
                else {
                    tmp = l2;
                    l2= l2->next;
                }
            }
            p->next=tmp;
            p=tmp;
        }
        
        p->next = NULL;
        
        return newhead;
    }
};