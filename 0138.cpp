/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* res = new Node(head->val, NULL, NULL);
        Node* node = res;
        Node* cur = head->next;
        unordered_map<Node*, Node*> m;
        m[head] = res;
        while (cur) {
            node->next = new Node(cur->val, NULL, NULL);
            m[cur] = node->next;
            cur = cur->next;
            node = node->next;
        }
        node = res;
        cur = head;
        while (node && cur) {
            node->random = m[cur->random];
            node = node->next;
            cur = cur->next;
        }
        return res;
    }
};