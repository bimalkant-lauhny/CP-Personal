/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    if (head == NULL)
        return -1;

    Node *fast = head; Node *slow = head;
    while(fast != NULL && fast->next != NULL) {
        //cout << fast->data << " " << slow->data << endl;
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}   

