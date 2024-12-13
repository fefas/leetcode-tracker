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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == NULL) return NULL;

        stack<ListNode*> s;
        for (ListNode* p = head; p; p = p->next) s.push(p);

        ListNode* tail = s.top();
        k = k % s.size();

        while (k--) s.pop();

        tail->next = head;
        head = s.top()->next;
        s.top()->next = NULL;

        return head;
    }
};