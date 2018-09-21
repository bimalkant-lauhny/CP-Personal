/* The method push to push element into the queue*/
void Queue:: push(int x)
{
    QueueNode *node = new QueueNode;
    node->data = x;
    node->next = NULL;
    if (front == NULL) {
        front = node;
    } else {
        rear->next = node;
    }
    rear = node;
}
/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{
    if (front == NULL) 
        return -1;
    QueueNode *temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    int data = temp->data;
    delete temp;
    return data;
}
