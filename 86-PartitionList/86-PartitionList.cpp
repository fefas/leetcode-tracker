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
    ListNode* partition(ListNode* head, int x)
    {
        head = new ListNode(-101, head);

        ListNode* lowerTail = head;
        while (lowerTail->next && lowerTail->next->val < x)
            lowerTail = lowerTail->next;
        
        ListNode* greaterTail = lowerTail;
        while (greaterTail->next && greaterTail->next->val >= x)
            greaterTail = greaterTail->next;

        while (greaterTail->next) {
            ListNode* p = greaterTail->next;

            if (p->val >= x) {
                greaterTail = greaterTail->next;
                continue;
            }

            greaterTail->next = p->next;
            p->next = lowerTail->next;
            lowerTail->next = p;
            lowerTail = p;
        }
        
        return head->next;
    }
};