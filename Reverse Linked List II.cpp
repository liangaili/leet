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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m==n) {
            return head;
        }
        ListNode * htail = NULL;
        ListNode * thead = NULL;
        ListNode * chead = NULL;
        ListNode * ctail = NULL;
        
        if (m>1) {
            htail = head;
            for (int i=2; i<m; i++) {
                htail = htail->next;
            }
        }
        
        if (htail == NULL ) {
            chead = ctail = head;
        }
        else {
            ctail = htail->next;
            chead = htail->next;
        }
        
        if (m<n) {
            thead = ctail->next;
            for (int i=m; i<n; i++) {
                ListNode * tmp = thead->next;
                if (thead!=NULL)
                    thead->next = chead;
                chead = thead;
                thead = tmp;
            }
        }
        
        ctail->next = thead;

      
        if (htail != NULL) {
            htail->next = chead;
            return head;
        }
        else {
            return chead;
        }
    }
};
