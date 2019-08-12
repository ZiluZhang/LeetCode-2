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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        int val = root->val;
        return checkUnival(root, val);
    }
    
    bool checkUnival(TreeNode* root, int val) {
        if (!root) return true;
        return root->val == val && checkUnival(root->left, val) && checkUnival(root->right, val);
    }
};