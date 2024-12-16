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
    unordered_map<Node*,int> original;
    unordered_map<int,Node*> copied;

    Node* mapList(Node* head, int i = 0)
    {
        if (head == NULL)
            return NULL;
        
        Node* copy = new Node(head->val);

        copy->next = mapList(head->next, i + 1);

        original[head] = i;
        copied[i] = copy;

        return copy;
    }

public:
    Node* copyRandomList(Node* head)
    {
        Node* newHead = mapList(head);

        for (Node* p = head, *q = newHead; p; p = p->next, q = q->next) {
            if (p->random)
                q->random = copied[original[p->random]];
        }
        
        return newHead;
    }
};