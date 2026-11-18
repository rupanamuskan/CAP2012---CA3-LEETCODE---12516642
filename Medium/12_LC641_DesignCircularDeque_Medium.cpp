class MyCircularDeque {
    struct Node {
        int val;
        Node *prev, *next;
        Node(int v) : val(v), prev(nullptr), next(nullptr) {}
    };
    Node *head, *tail;
    int size, cap;
public:
    MyCircularDeque(int k) {
        head = tail = nullptr;
        size = 0;
        cap = k;
    }
    bool insertFront(int value) {
        if (isFull()) return false;
        Node* n = new Node(value);
        if (isEmpty()) head = tail = n;
        else { n->next = head; head->prev = n; head = n; }
        size++;
        return true;
    }
    bool insertLast(int value) {
        if (isFull()) return false;
        Node* n = new Node(value);
        if (isEmpty()) head = tail = n;
        else { tail->next = n; n->prev = tail; tail = n; }
        size++;
        return true;
    }
    bool deleteFront() {
        if (isEmpty()) return false;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        size--;
        return true;
    }
    bool deleteLast() {
        if (isEmpty()) return false;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
        return true;
    }
    int getFront() { return isEmpty() ? -1 : head->val; }
    int getRear() { return isEmpty() ? -1 : tail->val; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == cap; }
};
