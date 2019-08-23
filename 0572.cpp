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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        queue<TreeNode*> q;
        q.push(s);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->val == t->val && checkEqual(cur, t)) {
                return true;
            }
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return false;
    }
    
    bool checkEqual(TreeNode* s1, TreeNode* s2) {
        if (!s1 && !s2) return true;
        if (!s1 || !s2) return false;
        return s1->val == s2->val && checkEqual(s1->left, s2->left) && checkEqual(s1->right, s2->right);
    }
};