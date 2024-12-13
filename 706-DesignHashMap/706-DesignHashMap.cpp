class MyHashMap {
private:
    struct Node {
        int k;
        int v;
        Node* n;
        Node(int k, int v, Node* n) : k(k), v(v), n(n) {}
    };

    Node* map[100];

    Node* findNode(int k)
    {
        Node* p = map[k % 100];

        while (p->n && p->n->k < k)
            p = p->n;

        return p;
    }

public:
    MyHashMap()
    {
        memset(map, 0, sizeof(map));

        for (int i = 0; i < 100; i++) {
            map[i] = new Node(-1, -1, NULL);
        }
    }
    
    void put(int k, int v)
    {
        Node* p = findNode(k);

        if (p->n == NULL || p->n->k != k) {
            p->n = new Node(k, v, p->n);
        } else {
            p->n->v = v;
        }
    }
    
    int get(int k)
    {
        Node* p = findNode(k);

        return p->n == NULL || p->n->k != k ? -1 : p->n->v;
    }
    
    void remove(int k)
    {
        Node* p = findNode(k);

        if (p->n == NULL || p->n->k != k)
            return;
        
        p->n = p->n->n;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */