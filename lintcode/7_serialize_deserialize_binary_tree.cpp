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
    vector <int> serializedList;
    vector <int> deserializedList;
public:
    
    // Storing preorder traversal in serializeHelper, using -1 for NULL
    void serializeHelper(TreeNode * node) {
        if (node == NULL) {
            serializedList.push_back(-1);
            return;
        }
        
        serializedList.push_back(node->val);
        serializeHelper(node->left);
        serializeHelper(node->right);
    }
     
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        serializeHelper(root);
        string data = "{";
        for (int i=0; i<serializedList.size(); ++i) {
            if (serializedList[i] == -1) {
                data += "#";
            } else {
                data += to_string(serializedList[i]);
            }
            data += ",";
        }
        if (data[data.size()-1] == ',')
            data.erase(data.size()-1, 1);
        data += "}";
        
        return data;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        int i=1;
        while (i<data.size()-1) {
            if (data[i] == ',') {
                ++i;
                continue;
            }
            
            int val = 0;
            if (data[i] == '#') {
                val = -1;
            } else {
                while (data[i] != ',') {
                    val = (val * 10) + (data[i] - '0');
                    ++i;
                }
            }
            deserializedList.push_back(val);
            ++i;
        }
        
        TreeNode* root = NULL;
        int index = 0;
        deserializeHelper(root, index);
        return root;
    }
    
    void deserializeHelper(TreeNode* & node, int& index) {
        if (index == deserializedList.size() || deserializedList[index] == -1) {
            index += 1;
            node = NULL;
            return;
        }
        
        node = new TreeNode (deserializedList[index]);
        index += 1;
        deserializeHelper(node->left, index);
        deserializeHelper(node->right, index);
    }
};