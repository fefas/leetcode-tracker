/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*,Node*> m;

public:
    Node* copyRandomList(Node* head)
    {
        for (Node* p = head; p; p = p->next) {
            m[p] = new Node(p->val);
        }

        for (Node* p = head; p; p = p->next) {
            Node* c = m[p];
            c->next = m[p->next];
            c->random = p->random == NULL ? NULL : m[p->random];
        }
        
        return m[head];
    }
};