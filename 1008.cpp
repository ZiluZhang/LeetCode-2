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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(root);
        for (int i = 1; i < n; i++) {
            TreeNode* tmp = s.top();
            TreeNode* cur = new TreeNode(preorder[i]);
            while (!s.empty() && s.top()->val < preorder[i]) {
                tmp = s.top(); s.pop();
            }
            
            if (tmp->val < preorder[i])
                tmp->right = cur;
            else
                tmp->left = cur;
            s.push(cur);
        }
        return root;
    }
};