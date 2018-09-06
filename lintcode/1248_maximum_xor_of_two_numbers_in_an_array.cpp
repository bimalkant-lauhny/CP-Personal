class TrieNode {
    /**
     * A node of a Trie Trie
     */
public:
    int val; 
    TrieNode *children[2];
    TrieNode() {
        val = 0; 
        children[0] = children[1] = nullptr;
    } 
};

class Solution {
    TrieNode *root;
public:
    /**
     * @param nums: 
     * @return: the maximum result of ai XOR aj, where 0 â‰¤ i, j < n
     */
    
    int maxXORutil(int key) {
        TrieNode *node = root; 
        for(int i=31; i>=0; --i) {
            bool curbit = key & (1<<i);
            if (node->children[1-curbit])
                node = node->children[1-curbit];
            else
                node = node->children[curbit];
        }
        return node->val ^ key;
    }
    
    void insertKey(int key) {
        TrieNode *node = root;
        for (int i=31; i>=0; --i) {
            bool curbit = key & (1<<i);
            if (node->children[curbit] == nullptr)
                node->children[curbit] = new TrieNode;
            node = node->children[curbit];
        }
        node->val = key;
    }
    
    int findMaximumXOR(vector<int> &nums) {
        root = new TrieNode;
        for (int i=0; i<nums.size(); ++i) {
            insertKey(nums[i]);
        }
        
        int maxXOR = 0;
        for (int i=0; i<nums.size(); ++i) {
            maxXOR = max(maxXOR, maxXORutil(nums[i]));
        }
        
        return maxXOR;
    }
};
