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
        ListNode* sum = NULL;
        stack<int> n1, n2;

        for (ListNode* p = l1; p; p = p->next) n1.push(p->val);
        for (ListNode* p = l2; p; p = p->next) n2.push(p->val);
        
        int val = 0;
        do {
            if (!n1.empty()) { val += n1.top(); n1.pop(); }
            if (!n2.empty()) { val += n2.top(); n2.pop(); }

            sum = new ListNode(val % 10, sum);
            val = val / 10;
        } while (!n1.empty() || !n2.empty() || val > 0);

        return sum;
    }
};