int getKthLargest(Node *root, int k, int &c) {
    if (root == NULL || c >=k) return -1;
    int right = getKthLargest(root->right, k, c);
    if (right != -1)
        return right;
    ++c;
    if (c == k) {
        return root->key;
    }
    return getKthLargest(root->left, k, c);
}
/*Complete the function below*/
void kthLargest(Node *root, int k)
{
    int c = 0;
    cout << getKthLargest(root, k, c) << endl;
}
