class MyHashSet {
private:
    int values[31251];

    int pos(int k)
    {
        return k / 32;
    }

    int mask(int k)
    {
        return 1 << (k % 32);
    }

public:
    MyHashSet()
    {
        memset(values, 0, sizeof(values));
    }
    
    void add(int key)
    {
        values[pos(key)] |= mask(key);
    }
    
    void remove(int key)
    {
        if (contains(key))
            values[pos(key)] ^= mask(key);
    }
    
    bool contains(int key)
    {
        return (values[pos(key)] & mask(key)) != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */