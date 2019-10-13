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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre, 0, pre.size()-1, post, 0, post.size()-1);
    }
    
    TreeNode* helper(vector<int>& pre, int x1, int y1, vector<int>& post, int x2, int y2) {
        if (x1 > y1 || x2 > y2) return NULL;
        TreeNode* root = new TreeNode(pre[x1]);
        if (x1 == y1) return root;
        int idx = -1;
        for (int i = x2; i <= y2; i++) {
            if (post[i] == pre[x1+1]) {
                idx = i;
                break;
            }
        }
        TreeNode* l = helper(pre, x1+1, x1+1+idx-x2, post, x2, idx);
        TreeNode* r = helper(pre, x1+1+idx-x2+1, y1, post, idx+1, y2);
        root->left = l;
        root->right = r;
        return root;
    }
};