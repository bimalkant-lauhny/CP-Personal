/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
    TreeNode *last = NULL;
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        
        if (root == NULL)
            return;
            
        // recursive
        /*
        flatten(root->right);
        flatten(root->left);
        
        root->right = last;
        root->left = NULL;
        last = root;
        */
        
        // iterative
        while(root) {
            if (root->left) {
                TreeNode *node = root->left;
                while(node->right) node = node->right;
                node->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};
