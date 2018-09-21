/* The method push to push element into the stack */
void Stack :: push(int x)
{
    StackNode *node = new StackNode;
    node->data = x;
    node->next = NULL;
    if (top != NULL) {
        node->next = top;
    }
    top = node;
}
/*The method pop which return the element poped out of the stack*/
int Stack :: pop()
{
    if (top == NULL)
        return -1;
    StackNode *temp = top;
    top = top->next;
    int data = temp->data;
    delete temp;
    return data;
}

