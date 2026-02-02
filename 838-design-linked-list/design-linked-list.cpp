class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int length() {
        Node* temp = head;
        int count = 0;
        while (temp) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    int get(int index) {
        Node* temp = head;
        int i = 0;
        while (temp) {
            if (i == index) return temp->val;
            temp = temp->next;
            i++;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addAtIndex(int index, int val) {
        int len = length();
        if (index < 0 || index > len) return;

        if (index == 0) return addAtHead(val);
        if (index == len) return addAtTail(val);

        Node* prev = head;
        for (int i = 0; i < index - 1; i++) prev = prev->next;

        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    void deleteAtIndex(int index) {
        int len = length();
        if (index < 0 || index >= len) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (!head) tail = nullptr;
            return;
        }

        Node* prev = head;
        for (int i = 0; i < index - 1; i++) prev = prev->next;

        Node* del = prev->next;
        prev->next = del->next;
        if (del == tail) tail = prev;
        delete del;
    }
};
