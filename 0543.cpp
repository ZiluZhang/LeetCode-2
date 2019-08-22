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
    int res;
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        getDepth(root);
        return res;
    }
    
    int getDepth(TreeNode* tmp) {
        if (!tmp) return 0;
        int l = getDepth(tmp->left);
        int r = getDepth(tmp->right);
        res = max(res, l + r);
        return max(l, r) + 1;
    }
};