/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        map<ListNode*,bool> m;

        while (head && !m.contains(head)) {
            m[head] = true;
            head = head->next;
        }

        return head;
    }
};