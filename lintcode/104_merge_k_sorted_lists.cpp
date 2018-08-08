/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class Solution {

public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */

    ListNode *mergeKLists(vector<ListNode *> &lists) {

        if (lists.size() == 0) {
            return NULL;
        }

        auto compare = [](ListNode *a, ListNode *b){
           return a->val > b->val; 
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> pq(compare);

        for (auto const &i: lists) {
            if (i != NULL) {
                pq.push(i);
            }
        }

        ListNode *dummy = new ListNode(0); 
        ListNode *tail = dummy;

        while (!pq.empty()) {
            ListNode *cur = pq.top();
            pq.pop();
            tail->next = cur;
            tail = cur;
            if (cur->next != NULL) {
                pq.push(cur->next); 
            }
        }

        return dummy->next;
    }
};
