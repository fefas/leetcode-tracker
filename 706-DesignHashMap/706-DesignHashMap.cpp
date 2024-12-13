struct Node {
    int k;
    int v;
    Node *n;
};

class MyHashMap {
private:
    Node* map[15626];

    Node* findNode(int k)
    {
        Node* p = map[k / 64];

        while (p->n && p->n->k < k)
            p = p->n;

        return p;
    }

public:
    MyHashMap()
    {
        memset(map, 0, sizeof(map));

        for (int i = 0; i < 15626; i++) {
            Node *p = new Node();
            p->k = p->v = -1;
            p->n = NULL;

            map[i] = p;
        }
    }
    
    void put(int k, int v)
    {
        Node* p = findNode(k);

        if (p->n == NULL || p->n->k != k) {
            Node* n = new Node();
            n->k = k;
            n->n = p->n;
            p->n = n;
        }
        
        p->n->v = v;
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