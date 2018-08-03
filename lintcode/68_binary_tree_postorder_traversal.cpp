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
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        vector<int> postord;
        
        if (!root) 
            return postord;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            
            postord.push_back(node->val); 
            
            if (node->left) {
                st.push(node->left);
            }
            
            if (node->right) {
                st.push(node->right);
            }
        }
        
        reverse(postord.begin(), postord.end());
        return postord;
    } 
};
