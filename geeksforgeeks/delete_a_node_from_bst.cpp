Node * deleteNode(Node *root,  int x)
{
    if (root == NULL)
        return root;

    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->left && root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        } else if (root->right && root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else {
            Node *inSuc = root->right;
            while(inSuc->left) {
                inSuc = inSuc->left;
            }

            root->data = inSuc->data;
            root->right = deleteNode(root->right, inSuc->data);
        }
    }
    return root;
}
