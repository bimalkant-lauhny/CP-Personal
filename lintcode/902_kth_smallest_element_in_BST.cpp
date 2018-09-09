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
         * @param root: the given BST
         * @param k: the given k
         * @return: the kth smallest element in BST
         */
        int kthSmallest(TreeNode * root, int k) {
            TreeNode * pCrawl = root;
            stack<TreeNode*> st;

            while (pCrawl) {
                st.push(pCrawl);
                pCrawl = pCrawl->left;
            }

            while(!st.empty()) {
                pCrawl = st.top();
                st.pop();
                --k;
                if (!k) {
                    return pCrawl->val;
                }
                if (pCrawl->right) {
                    pCrawl = pCrawl->right;
                    while (pCrawl) {
                        st.push(pCrawl);
                        pCrawl = pCrawl->left;
                    }
                }
            }
        }
};
