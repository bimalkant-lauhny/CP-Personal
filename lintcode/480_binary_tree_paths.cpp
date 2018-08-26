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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    
    vector<string> binaryTreePaths(TreeNode * root) {
        
        vector <string> res;
        if (root == NULL) {
            return res;    
        }
        
        string vstr = "";
        vstr = to_string(root->val);
        
        if (root->left != NULL) {
            vector<string> l = binaryTreePaths(root->left);
            string vtmp = vstr + "->";
            for (int i=0; i<l.size(); ++i) {
                res.push_back(vtmp + l[i]);
            }
        }
        
        if (root->right != NULL) {
            vector<string> r = binaryTreePaths(root->right);
            string vtmp = vstr + "->";
            for (int i=0; i<r.size(); ++i) {
                res.push_back(vtmp + r[i]);
            }
        }
        
        if (res.size() == 0) {
            res.push_back(vstr);
        }
            
        return res;
    }
};
