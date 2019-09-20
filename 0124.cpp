/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        // if (!root) return 0;
        helper(root, res);
        return res;
    }
    
    int helper(TreeNode* cur, int& res) { // return max value of cur to leaf path
        if (!cur) return 0;
        res = max(res, cur->val);
        int left = max(helper(cur->left, res), 0);
        int right = max(helper(cur->right, res), 0);
        res = max(res, cur->val + left + right);
        return max(left, right) + cur->val;
    }
};