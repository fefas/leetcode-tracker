/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

const int init = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;

        while (fast && fast->next) {
            head = head->next;
            fast = fast->next->next;

            if (fast == head)
                return true;
        }

        return false;
    }
};