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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(getDepth(root->left) - getDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};