/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

const int ZERO = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    Node* flatten(Node* head)
    {
        stack<Node*> s;

        for (Node* p = head; p; p = p->next)
            if (p->child) {
                if (p->next) s.push(p->next);
                p->next = p->child;
                p->next->prev = p;
                p->child = NULL;
            } else if (!p->next && !s.empty()) {
                p->next = s.top();
                p->next->prev = p;
                s.pop();
            }
        
        return head;
    }
};