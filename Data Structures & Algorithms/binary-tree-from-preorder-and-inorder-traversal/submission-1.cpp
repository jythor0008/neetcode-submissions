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
        if(preorder.empty()) return nullptr;

        int rootVal = preorder[0];
        int idx = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();

        vector<int> inorderLeft = vector<int>(inorder.begin(), inorder.begin() + idx);
        vector<int> inorderRight = vector<int>(inorder.begin() + idx + 1, inorder.end());

        vector<int> preorderLeft = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + inorderLeft.size());
        vector<int> preorderRight = vector<int>(preorder.begin() + 1 + inorderLeft.size(), preorder.end());

        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }
};
