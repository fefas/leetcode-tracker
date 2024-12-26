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
        for (ListNode* p = head; p; p = p->next)
            N++;

        int l = N - k;
        ListNode* pk, *pl;
        for (ListNode* p = head; p; p = p->next) {
            if (--k == 0) pk = p;
            if (l-- == 0) pl = p;
        }

        l = pk->val;
        pk->val = pl->val;
        pl->val = l;

        return head;
    }
};