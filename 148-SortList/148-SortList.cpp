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
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        
        ListNode* beforeHalf = head;
        ListNode* half = head->next;
        for (ListNode* fast = head->next; fast && fast->next; fast = fast->next->next) {
            beforeHalf = half;
            half = half->next;
        }
        beforeHalf->next = NULL;

        ListNode* sorted1 = sortList(head);
        ListNode* sorted2 = sortList(half);

        head = new ListNode(-100001);
        ListNode* p = head;
        while (sorted1 && sorted2) {
            if (sorted1->val < sorted2->val) {
                p->next = sorted1;
                sorted1 = sorted1->next;
            } else {
                p->next = sorted2;
                sorted2 = sorted2->next;
            }
            p = p->next;
        }
        if (sorted1) p->next = sorted1;
        if (sorted2) p->next = sorted2;

        return head->next;
    }
};