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
    bool isPalindrome(ListNode* head)
    {
        stack<ListNode*> s;

        for (ListNode *p = head; p; p = p->next) s.push(p);

        for (int i = s.size() / 2; i >= 0; i--) {
            if (head->val != s.top()->val)
                return false;

            head = head->next;
            s.pop();
        }

        return true;
    }
};