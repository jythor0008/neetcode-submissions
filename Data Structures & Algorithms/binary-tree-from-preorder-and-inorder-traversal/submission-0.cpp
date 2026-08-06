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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // inorder tells us where the separatation between left and right is
        // preorder tells us which is the root
        if(preorder.empty()) return nullptr;

        int rootVal = preorder[0];
        int idx = find(inorder.begin(), inorder.end(), rootVal)  - inorder.begin();

        TreeNode* root = new TreeNode(inorder[idx]);

        // left side 
        vector<int> inLeft = vector<int>(inorder.begin(), inorder.begin() + idx); 
        vector<int> inRight = vector<int>(inorder.begin() + idx + 1, inorder.end()); 
        vector<int> preLeft = vector<int>(preorder.begin()+1, preorder.begin() + 1 + inLeft.size());
        vector<int> preRight = vector<int>(preorder.begin() + 1 + inLeft.size(), preorder.end());

        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);

        return root;
    }
};
