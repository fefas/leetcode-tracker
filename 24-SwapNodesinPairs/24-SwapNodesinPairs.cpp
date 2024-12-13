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
    ListNode* swapPairs(ListNode* head)
    {
        head = new ListNode(-1, head);

        ListNode* p = head;
        while (p->next && p->next->next) {
            ListNode* n1 = p->next;
            ListNode* n2 = p->next->next;

            p->next = n2;
            n1->next = n2->next;
            n2->next = n1;

            p = n1;
        }
        
        return head->next;
    }
};