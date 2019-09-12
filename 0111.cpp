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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int minleft = minDepth(root->left);
        int minright = minDepth(root->right);
        if (minleft == 0) return minright+1;
        else if (minright == 0) return minleft+1;
        else return min(minright, minleft) + 1;
    }
};