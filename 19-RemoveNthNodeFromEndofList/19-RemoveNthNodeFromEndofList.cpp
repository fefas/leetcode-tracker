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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        head = new ListNode(-1, head);
        stack<ListNode*> s;

        for (ListNode* p = head; p; p = p->next) s.push(p);

        while (n--) s.pop();

        s.top()->next = s.top()->next->next;

        return head->next;
    }
};