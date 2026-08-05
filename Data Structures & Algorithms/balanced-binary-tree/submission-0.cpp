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
    bool balanced;
public:
    bool isBalanced(TreeNode* root) {
        balanced = true;
        dfs(root);
        return balanced;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        if(!balanced) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(abs(right - left) > 1) balanced = false;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
};
