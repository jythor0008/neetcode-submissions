/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        encode(root, res);
        return res;
    }

    void encode(TreeNode* root, string& res){
        if(!root){
            res += "N#";
            return;
        }

        string val = to_string(root->val);
        res += val + "#"; // no need length because we can just keep going until we meet a #

        encode(root->left, res);
        encode(root->right, res);
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return decode(data, i);
    }

    TreeNode* decode(string& data, int& i){
        if(i >= data.size()) return nullptr;
        
        string cur = "";
        while(i < data.size() && data[i] != '#'){
            cur += data[i++];
        }

        i++; // get rid of #

        if(cur == "N") return nullptr;

        int val = stoi(cur);
        TreeNode* root = new TreeNode(val);
        root->left = decode(data, i);
        root->right = decode(data, i);
        return root;
    }
};
