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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> lot;
        
        if (root == NULL) {
            return lot;
        }
        
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            pair<TreeNode*, int> e = q.front();
            
            if (e.second == lot.size()) {
               lot.push_back(vector<int>{e.first->val});
            } else {
               lot[e.second].push_back(e.first->val);
            }
            
            q.pop();
            
            if (e.first->left != NULL) {
                q.push(make_pair(e.first->left, e.second+1)); 
            }
            
            if (e.first->right != NULL) {
                q.push(make_pair(e.first->right, e.second+1)); 
            }
        }
        
        return lot;
    }
};
