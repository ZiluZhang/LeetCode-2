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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        getPath(root, "", res);
        return res;
    }
    
    void getPath(TreeNode* tmp, string cur, vector<string>& res) {
        if (!tmp) return;
        cur += to_string(tmp->val);
        if (!tmp->left && !tmp->right) {
            res.push_back(cur);
        } else {
            cur += "->";
            getPath(tmp->left, cur, res);
            getPath(tmp->right, cur, res);
        }
    }
};