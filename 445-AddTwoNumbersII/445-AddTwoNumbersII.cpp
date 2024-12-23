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

const int ZERO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* sum = NULL;
        stack<int> n1, n2;

        for (; l1; l1 = l1->next)
            n1.push(l1->val);
        for (; l2; l2 = l2->next)
            n2.push(l2->val);
        
        for (int val = 0; val > 0 || !n1.empty() || !n2.empty(); val /= 10) {
            if (!n1.empty()) {
                val += n1.top(); n1.pop(); }
            if (!n2.empty()) {
                val += n2.top();
                n2.pop();
            }

            sum = new ListNode(val % 10, sum);
        }

        return sum;
    }
};