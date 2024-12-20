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
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode* oddHead = new ListNode(-1);
        ListNode* evenHead = new ListNode(-1);

        ListNode* p = head;
        ListNode* o = oddHead;
        ListNode* e = evenHead;
        while (p) {
            o->next = p;
            e->next = p->next;

            o = o->next;
            e = e->next;

            if (!p->next) break;

            p = p->next->next;
            o->next = NULL;
            e->next = NULL;
        }

        o->next = evenHead->next;
        
        return oddHead->next;
    }
};