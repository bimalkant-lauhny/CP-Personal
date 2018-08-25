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
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode * plusOne(ListNode * head) {
        ListNode* lsNonNine = NULL; // least significant non Nine
        ListNode* currentNode = head;
        while(currentNode) {
            if (currentNode->val < 9)
                lsNonNine = currentNode;
            currentNode = currentNode->next;
        }
        
        ListNode* newHead = head;
        if (lsNonNine == NULL) {
            newHead = new ListNode(1);
            newHead->next = head;
            currentNode = head;
        } else {
            lsNonNine->val += 1;
            currentNode = lsNonNine->next;
        }
        
        while (currentNode) {
            currentNode->val = 0;
            currentNode = currentNode->next;
        }
        
        return newHead;
    }
};
