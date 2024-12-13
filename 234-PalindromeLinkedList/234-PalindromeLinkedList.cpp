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
    ListNode *left;

    bool bla(ListNode* right)
    {
        if (right == NULL)
            return true;

        if (!bla(right->next))
            return false;

        if (left->val == right->val) {
            left = left->next;
            return true;
        }
        
        return false;
    }

public:
    bool isPalindrome(ListNode* head)
    {
        left = head;

        return bla(head);
    }
};