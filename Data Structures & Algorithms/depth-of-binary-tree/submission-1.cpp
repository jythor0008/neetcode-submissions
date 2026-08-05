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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        if(root) s.push({root, 1});
        TreeNode* cur;
        int depth;
        int res = 0;
        while(!s.empty()){
            cur = s.top().first;
            depth = s.top().second;
            s.pop();

            if(cur->left)s.push({cur->left, depth + 1});
            if(cur->right)s.push({cur->right, depth + 1});

            res = max(res, depth);
        }

        return res;

    }
};
