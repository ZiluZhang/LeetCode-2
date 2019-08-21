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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* tmp;
        if (!t1 && !t2) return NULL;
        else if (t1 && t2) {
            tmp = new TreeNode(t1->val + t2->val);
            tmp->left = mergeTrees(t1->left, t2->left);
            tmp->right = mergeTrees(t1->right, t2->right);
        } else if (t1) {
            tmp = new TreeNode(t1->val);
            tmp->left = t1->left;
            tmp->right = t1->right;
        } else {
            tmp = new TreeNode(t2->val);
            tmp->left = t2->left;
            tmp->right = t2->right;
        }
        return tmp;
    }
};