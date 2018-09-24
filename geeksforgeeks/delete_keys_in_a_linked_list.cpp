Node* deleteAllOccurances(Node *head,int x)
{
    Node *dummyHead = new Node;
    dummyHead->next = head;
    Node *cur = head, *prev = dummyHead;
    while (cur != NULL) {
        if (cur->data == x) {
            Node *temp = cur;
            cur = cur->next;
            prev->next = cur;
            delete temp;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return dummyHead->next;
}
