class MyHashMap {
private:
    struct Node {
        int k;
        int v;
        Node* n;
        Node(int k, int v) : k(k), v(v), n(NULL) {}
    };

    Node* map[1000];

    Node* findNode(int k)
    {
        Node* p = map[k % 1000];

        while (p->n && p->n->k < k)
            p = p->n;

        return p;
    }

    Node* findList(int k)
    {
        return map[k % 1000];
    }

public:
    MyHashMap()
    {
        memset(map, 0, sizeof(map));

        for (int i = 0; i < 1000; i++) {
            map[i] = new Node(-1, -1);
        }
    }
    
    void put(int k, int v)
    {
        Node* p = findList(k);
        while (p->n && p->n->k != k) p = p->n;

        if (p->n) p->n->v = v;
        else p->n = new Node(k, v);
    }
    
    int get(int k)
    {
        Node* p = findList(k);
        while (p->n && p->n->k != k) p = p->n;

        return p->n ? p->n->v : -1;
    }
    
    void remove(int k)
    {
        Node* p = findList(k);
        while (p->n && p->n->k != k) p = p->n;

        if (p->n) p->n = p->n->n;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */