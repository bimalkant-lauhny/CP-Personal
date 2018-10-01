void deleteNode(Node *node)
{
   // Your code here
    Node *prev = node,
         *cur = node->next,
         *next = node->next->next;
    
    prev->data = cur->data;
    prev->next = next;
    delete cur;
}
