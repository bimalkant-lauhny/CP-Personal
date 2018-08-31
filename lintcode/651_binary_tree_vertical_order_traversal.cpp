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
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    
    vector<vector<int>> verticalOrder(TreeNode * root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        map <int, vector<int>> vertOrd;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode *, int> cur = q.front();
            q.pop();
            vertOrd[cur.second].push_back(cur.first->val);
            if (cur.first->left) {
                q.push(make_pair(cur.first->left, cur.second-1));
            }
            if (cur.first->right) {
                q.push(make_pair(cur.first->right, cur.second+1));
            }
            
        }
        
        for (auto it = vertOrd.begin(); it != vertOrd.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};
