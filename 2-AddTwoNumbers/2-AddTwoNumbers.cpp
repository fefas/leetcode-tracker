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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* ans = new ListNode();
        
        int current = 0, remaining = 0;
        ListNode* p = ans;

        while (remaining || l1 || l2) {
            current = remaining;
            if (l1) { current += l1->val; l1 = l1->next; }
            if (l2) { current += l2->val; l2 = l2->next; }

            p->next = new ListNode(current % 10);
            remaining = current / 10;

            p = p->next;
        }
        
        return ans->next;
    }
};