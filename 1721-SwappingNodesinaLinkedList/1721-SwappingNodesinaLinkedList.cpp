/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        int N = 0;
        ListNode* p1;
        ListNode* p2;

        for (ListNode* p = head; p; p = p->next)
            if (++N == k) p1 = p;

        p2 = head;
        for (int i = N - k; i > 0; i--)
            p2 = p2->next;

        N = p1->val;
        p1->val = p2->val;
        p2->val = N;

        return head;
    }
};