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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        head = new ListNode(-501, head);

        int i = 0;

        ListNode* pL = head;
        for (int i = 0; i < left - 1; i++) pL = pL->next;

        ListNode* pR = pL->next;
        for (int i = right - left; i > 0; i--) {
            ListNode* pS = pR->next;

            pR->next = pS->next;
            pS->next = pL->next;
            pL->next = pS;
        }

        return head->next;
    }
};