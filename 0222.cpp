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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int d = getDepth(root);
        if (d == 0) return 1;
        
        int left = 1, right = pow(2, d) - 1;
        int last = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nodeExist(root, mid, d)) {
                last = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << last << endl;
        return pow(2, d) - 1 + last + 1;
    }
    
    bool nodeExist(TreeNode* root, int idx, int d) {
        int left = 0, right = pow(2, d) - 1;
        for (int i = 0; i < d; i++) {
            int mid = left + (right - left) / 2;
            if (idx <= mid) {
                root = root->left;
                right = mid - 1;
            } else {
                root = root->right;
                left = mid + 1;
            }
        }
        return root != NULL;
    }
    
    int getDepth(TreeNode* root) {
        int d = 0;
        while (root->left) {
            d++;
            root = root->left;
        }
        return d;
    }
};