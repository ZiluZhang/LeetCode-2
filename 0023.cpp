/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Comp {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> q;
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            if (cur->next->next) {
                q.push(cur->next->next);
            }
            cur = cur->next;
        }
        return res->next;
    }
};