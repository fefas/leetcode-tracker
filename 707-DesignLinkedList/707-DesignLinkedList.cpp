const int ZERO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class MyLinkedList {
private:
    const int NOT_FOUND = -1;
    const int HEAD = -2;
    const int TAIL = -3;

    struct Node {
        int val;
        Node* next;

        Node(int _v) : val(_v), next(NULL) {}
        Node(int _v, Node* _n) : val(_v), next(_n) {}
    };

    Node* head;
    Node* tail;
    int len;

public:
    MyLinkedList()
    {
        tail = new Node(TAIL);
        head = new Node(HEAD, tail);
        len = 0;
    }
    
    int get(int index)
    {
         if (index >= len) {
            return NOT_FOUND;
        }

        Node* p = head->next;
        while (index--) p = p->next;

        return p->val;
    }
    
    void addAtHead(int val)
    {
        head->next = new Node(val, head->next);
        len++;
    }
    
    void addAtTail(int val)
    {
        tail->val = val;
        tail->next = new Node(TAIL);
        tail = tail->next;
        len++;
    }
    
    void addAtIndex(int index, int val)
    {
        if (index > len) {
            return;
        }
        
        if (len == index) {
            addAtTail(val);
            return;
        }

        Node* p = head;
        while (index--) p = p->next;
        
        p->next = new Node(val, p->next);
        len++;
    }
    
    void deleteAtIndex(int index)
    {
        if (index >= len) {
            return;
        }

        Node* p = head;
        while (index--) p = p->next;

        p->next = p->next->next;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */