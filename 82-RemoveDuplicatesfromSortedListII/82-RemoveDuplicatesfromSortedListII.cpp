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
    ListNode* deleteDuplicates(ListNode* head)
    {
        head = new ListNode(-101, head);

        for (ListNode* p = head; p;) {
            ListNode* q = p->next;
            if (q && q->next && q->val == q->next->val) {
                q = q->next;
                while (q->next && q->val == q->next->val) q = q->next;
                p->next = q->next;
            }
            else p = p->next;
        }
        
        return head->next;
    }
};