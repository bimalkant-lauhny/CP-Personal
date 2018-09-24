int detectloop(struct node *list){
    struct node *slow = list, *fast = list;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}
