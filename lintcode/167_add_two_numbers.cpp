/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode * addLists(ListNode * l1, ListNode * l2) {
        if (l1 == NULL ) {
            return l2;
        }
        
        if (l2 == NULL) 
            return l1;
            
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy, *cur1 = l1, *cur2 = l2;
        
        int carry = 0;
        while(cur1 != NULL && cur2 != NULL) {
            int res = cur1->val + cur2->val + carry;
            if (res > 9) {
                carry = 1;
                res -= 10;
            } else {
                carry = 0;
            }
            
            tail->next = new ListNode(res);
            tail = tail->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        while (cur1 != NULL) {
            int res = cur1->val + carry;
            if (res > 9) {
                carry = 1;
                res -= 10;
            } else {
                carry = 0;
            }
            tail->next = new ListNode(res);
            tail = tail->next;
            cur1 = cur1->next;
        }
        
        while (cur2 != NULL) {
            int res = cur2->val + carry;
            if (res > 9) {
                carry = 1;
                res -= 10;
            } else {
                carry = 0;
            }
            tail->next = new ListNode(res);
            tail = tail->next;
            cur2 = cur2->next;
        }
        if (carry == 1) {
            tail->next = new ListNode(1);
            tail = tail->next;
        }
        tail->next = NULL;
        return dummy->next;
    }
};
