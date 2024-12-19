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
private:
    void print(ListNode* head)
    {
        for (ListNode* p = head->next; p; p = p->next)
            cout << p->val << " ";
        cout << endl;
    }
public:
    ListNode* insertionSortList(ListNode* head)
    {
        head = new ListNode(-5001, head);

        for (ListNode* sorted = head->next; sorted->next;) {
            if (sorted->val <= sorted->next->val) {
                sorted = sorted->next;
                continue;
            }

            ListNode* search = head;
            while (search->next->val <= sorted->next->val) {
                search = search->next;
            }

            ListNode* tmp = sorted->next;

            sorted->next = tmp->next;
            tmp->next = search->next;
            search->next = tmp;
        }
        
        return head->next;
    }
};