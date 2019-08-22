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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = p->val;
        int y = q->val;
        int cur = root->val;
        if (x > cur && y > cur) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (x < cur && y < cur) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};