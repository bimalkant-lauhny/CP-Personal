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
     * @param root: root of the given tree
     * @return: whether it is a mirror of itself 
     */
    
    bool isMirror(TreeNode *node1, TreeNode *node2) {
        if (node1 == NULL && node2 == NULL) {
            return true;
        }
        
        if (node1 == NULL || node2 == NULL) {
            return false;
        }
        
        if (node1->val != node2->val) {
            return false;
        }
        
        return isMirror(node1->left, node2->right) &&
               isMirror(node1->right, node2->left);
    }
    
    bool isSymmetric(TreeNode * root) {
        return isMirror(root, root); 
    }
};
