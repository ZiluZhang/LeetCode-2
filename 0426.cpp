/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* first;
    Node* last;
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        helper(root);
        last->right = first;
        first->left = last;
        return first;
    }
    
    void helper(Node* node) {
        // if (node) {
        //     helper(node->left);
        //     if (last) {
        //         last->right = node;
        //         node->left = last;
        //     } else {
        //         first = node;
        //     }
        //     last = node;
        //     helper(node->right);
        // }
        if (!node) return;
        helper(node->left);
        if (last) {
            last->right = node;
            node->left = last;
        } else {
            first = node;
        }
        last = node;
        helper(node->right);
    }
};