struct Node {
    int val;
    Node *next;
};

class MyHashSet {
private:
    Node* l;

    Node* findClosest(int key)
    {
        Node *p = l;
        while (p->next && key > p->next->val)
            p = p->next;

        return p;
    }

public:
    MyHashSet()
    {
        l = new Node();
    }
    
    void add(int key)
    {
        Node *p = findClosest(key);
        
        if (p->next == NULL || p->next->val != key) {
            Node *n = p->next;
            p->next = new Node();
            p->next->val = key;
            p->next->next = n;
        }
    }
    
    void remove(int key)
    {
        Node *p = findClosest(key);
        
        if (p->next == NULL || p->next->val != key)
            return;

        p->next = p->next->next;
    }
    
    bool contains(int key)
    {
        Node *p = findClosest(key);

        return p->next != NULL && p->next->val == key;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */