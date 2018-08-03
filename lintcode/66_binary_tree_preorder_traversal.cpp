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
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> preord;
        
        if (!root)
            return preord;
        
        stack<TreeNode *> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            preord.push_back(node->val);
            if (node->right) {
                st.push(node->right);
            }
            
            if (node->left) {
                st.push(node->left);
            }
            
        }
        
        return preord;
    } 
};
