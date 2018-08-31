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
public:
    /**
     * @param root: The root of binary tree
     * @return: An integer
     */
    int dfs(TreeNode *node, int depth) {
        if (node->left == NULL && node->right == NULL) {
            // node is leaf
            return depth;
        }
        
        int lt = INT_MAX, rt = INT_MAX; 
        if (node->left) {
            lt = dfs(node->left, depth + 1); 
        }
        
        if (node->right) {
            rt = dfs(node->right, depth + 1);
        }
        
        return min(lt, rt);
    }
     
    int minDepth(TreeNode * root) {
        if (root == NULL)
            return 0;
        return dfs(root, 1);
    }
};
