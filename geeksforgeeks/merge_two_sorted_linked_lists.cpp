Node* SortedMerge(Node* head1,   Node* head2)
{
    Node *newHead = new Node, *newCur = newHead,
         *cur1 = head1, *cur2 = head2;
    while(cur1 && cur2) {
        if (cur1->data < cur2->data) {
            newCur->next = cur1;
            cur1 = cur1->next;
        } else {
            newCur->next = cur2;
            cur2 = cur2->next;
        }
        newCur = newCur->next;
    }

    while (cur1) {
        newCur->next = cur1;
        cur1 = cur1->next;
        newCur = newCur->next;
    }

    while (cur2) {
        newCur->next = cur2;
        cur2 = cur2->next;
        newCur = newCur->next;
    }

    return newHead->next;
}
