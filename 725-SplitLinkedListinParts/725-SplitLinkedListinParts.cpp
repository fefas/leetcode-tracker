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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        int size = 0;
        for (ListNode* p = head; p; p = p->next) size++;

        int N = size / k;
        int R = size % k;
        vector<ListNode*> ans;

        ListNode* p = head;
        for (int i = 1; i <= k; i++) {
            ans.push_back(p);

            if (!p)
                continue;

            int S = N + (R-- > 0 ? 1 : 0);
            for (int j = 1; j < S; j++) p = p->next;

            ListNode* tmp = p;
            p = p->next;
            tmp->next = NULL;
        }
        
        return ans;
    }
};