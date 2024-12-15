/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root, Node* next = NULL)
    {
        if (!root) return NULL;

        root->next = next;

        if (root->left) {
            if (root->right) connect(root->left, root->right);
            else if (next) connect(root->left, next->left ? next->left : next->right);
            else connect(root->left);
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                Node* n = q.front(); q.pop();

                n->next = i == 1 ? NULL : q.front();

                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        
        return root;
    }
};