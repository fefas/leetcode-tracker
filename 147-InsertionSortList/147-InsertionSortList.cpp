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

        for (ListNode* p = head->next; p->next;) {
            if (p->val <= p->next->val) {
                p = p->next;
                continue;
            }

            ListNode* s = head;
            while (s->next->val <= p->next->val) {
                s = s->next;
            }

            ListNode* tmp = p->next;

            p->next = tmp->next;
            tmp->next = s->next;
            s->next = tmp;
        }
        
        return head->next;
    }
};