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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *ans = new ListNode(-101, l1);

        for (ListNode *p = ans; l2 != NULL; p = p->next) {
            if (p->next == NULL) {
                p->next = l2;
                break;
            }

            if (p->next->val > l2->val) {
                ListNode *l2next = l2->next;

                l2->next = p->next;
                p->next = l2;

                l2 = l2next;
            }
        }

        return ans->next;
    }
};