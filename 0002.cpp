/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* res = new ListNode(-1);
        ListNode* tmp = res;
        while (l1 && l2) {
            int cur = l1->val + l2->val + c;
            res->next = new ListNode(cur % 10);
            c = cur / 10;
            l1 = l1->next;
            l2 = l2->next;
            res = res->next;
        }
        while (l1) {
            int cur = l1->val + c;
            res->next = new ListNode(cur % 10);
            c = cur / 10;
            l1 = l1->next;
            res = res->next;
        }
        while (l2) {
            int cur = l2->val + c;
            res->next = new ListNode(cur % 10);
            c = cur / 10;
            l2 = l2->next;
            res = res->next;
        }
        if (c) {
            res->next = new ListNode(c);
        }
        return tmp->next;
    }
};