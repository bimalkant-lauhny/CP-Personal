bool hasPathSum(Node *node, int sum)
{
    if (node->left == NULL && node->right == NULL) {
        if (sum == node->data)
            return true;
        else
            return false;
    }
    bool lsum = false, rsum = false;
    if (node->left) {
        lsum = hasPathSum(node->left, sum - node->data);
    }
    if (node->right) {
        rsum = hasPathSum(node->right, sum - node->data);
    }
    return lsum || rsum;
}
