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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        getRes(root, target, res);
        return res;
    }
    
    void getRes(TreeNode* tmp, double target, int& res) {
        if (!tmp) return;
        int cur = tmp->val;
        res = abs(cur - target) < abs(res - target) ? cur : res;
        if (cur < target) {
            getRes(tmp->right, target, res);
        } else {
            getRes(tmp->left, target, res);
        }
        return;
    }
};