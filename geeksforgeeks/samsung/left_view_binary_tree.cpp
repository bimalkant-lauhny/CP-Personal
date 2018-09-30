void leftViewHelper(Node *root, int &maxLevel, int level) {
    if (!root)
        return;
    if (maxLevel < level) {
        cout << root->data << " ";
        maxLevel = level;
    }
    leftViewHelper(root->left, maxLevel, level+1);
    leftViewHelper(root->right, maxLevel, level+1);
}

void leftView(Node *root)
{
    int maxLevel = -1;
    leftViewHelper(root, maxLevel, 0);
}
