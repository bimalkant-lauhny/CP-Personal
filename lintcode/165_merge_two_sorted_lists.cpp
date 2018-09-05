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
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        ListNode *dummyNode = new ListNode(0);
        ListNode *lastNode = dummyNode;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                lastNode->next = l1;
                l1 = l1->next;
            } else {
                lastNode->next = l2;
                l2 = l2->next;
            }
            lastNode = lastNode->next;
        }
        
        if (l1 != NULL) {
            lastNode->next = l1;
        } else {
            lastNode->next = l2;
        }
        
        return dummyNode->next;
    }
};
