#include <iostream>
#include <list>
#define random(min,max) min + rand() % (max - min + 1)
using namespace std;

template<typename T>
class MyList {
private:

    class Node {
    public:
        T elem;
        Node* next;
        Node* prev;

        Node(const T& value) : elem(value), next(nullptr), prev(nullptr) {};
    };

    Node* head;
    Node* tail;
    int size = 0;

public:
    MyList() : head(nullptr), tail(nullptr) {};

    MyList(const MyList& otherList) {
        if (otherList.empty()) return;
        this->size = otherList.size;
        Node* otherCur = otherList.head;
        this->push_back(otherCur->elem);

        while (otherCur->next != nullptr) {
            otherCur = otherCur->next;
            this->push_back(otherCur->elem);
        }
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (this->empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void pop_front() {
        if (empty()) throw out_of_range("Forward list is empty");
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* buf = head->next;
            delete head;
            head = buf;
            head->prev = nullptr;
        }
        size--;
    }


    bool empty() const {
        return head == nullptr;
    }

    void show() {
        if (empty()) return;
        Node* cur = head;
        while (cur->next != nullptr) {
            cout << cur->elem << " ";
            cur = cur->next;
        }
        cout << cur->elem << endl;
    }

    void insert_after(int index, const T& value) {

        if (empty() || index < 0 || index >= size) throw out_of_range("empty");
        Node* cur;
        find(cur, index);
        Node* buf = cur->next;
        cur->next = new Node(value);
        cur->next->next = buf;
        cur->next->prev = cur;
        buf->prev = cur->next;
        size++;

    }

    void emplace(int index, const T& value) {
        if (empty() || index < 0) throw out_of_range("empty");
        Node* cur = head;
        for (int i = 0; i < index; i++)
        {
            if (cur->next == nullptr) throw out_of_range("empty");
            cur = cur->next;
        }
        cur->elem = value;
    }

    void push_back(const T& value) {
        if (empty()) {
            head = new Node(value);
            tail = head;
            return;
        }
        tail->next = new Node(value);
        tail->next->prev = tail;
        tail = tail->next;
        size++;
    }

    void pop_back() {
        if (empty()) throw out_of_range("empty");
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        size--;
    }

    T& front() {
        return head->elem;
    }

    T& back() {
        return tail->elem;
    }

    void clear() {
        Node* cur = head;
        while (cur->next != nullptr) {
            Node* buf = cur->next;
            delete cur;
            cur = buf;
        }
        delete cur;
        head = nullptr;
        size = 0;
    }

    ~MyList() {
        if (!empty()) {
            Node* cur = head;
            Node* buf;
            while (cur->next != nullptr) {
                buf = cur->next;
                delete cur;
                cur = buf;
            }
            delete cur;
        }
    }

    bool operator == (const MyList& otherList) {
        Node* cur1 = this->head;
        Node* cur2 = otherList.head;

        while (true) {
            if ((cur1 == nullptr && cur2 != nullptr) ||
                (cur1 != nullptr && cur2 == nullptr)) return false;
            else if (cur1 == nullptr && cur2 == nullptr) break;
            else if (cur1->elem != cur2->elem) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }

    bool operator != (const MyList& otherList) {
        return !(*this == otherList);
    }

    MyList& operator = (const MyList& otherList) {
        this->clear();
        this->size = otherList.size;
        if (!(otherList.empty())) {
            Node* otherCur = otherList.head;
            this->push_back(otherCur->elem);

            while (otherCur->next != nullptr) {
                otherCur = otherCur->next;
                this->push_back(otherCur->elem);
            }
        }
        return *this;
    }

    class Iterator {
    private:
        Node* ptr;
    public:
        Iterator(Node* ptr) : ptr(ptr) {}
        T operator *() const {
            return ptr->elem;
        }
        Iterator operator ++() {
            this->ptr = this->ptr->next;
            return *this;
        }
        bool operator ==(const Iterator otherIter) {
            return this->ptr == otherIter.ptr;
        }
        bool operator !=(const Iterator otherIter) {
            return !(*this == otherIter);
        }
        Node* getPtr() {
            return ptr;
        }
        void setPtr(Node* ptr) {
            this->ptr = ptr;
        }

    };

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    Iterator erase(Iterator begin, Iterator end) {
        Node* start = begin.getPtr();
        Node* finish = end.getPtr();
        if (start == head && finish == tail) {
            this->clear();
            return Iterator(nullptr);
        }
        if (start == head && finish != tail) {
            finish->next->prev = nullptr;
            this->head = finish->next;
        }
        else if (start != head && finish == tail) {
            start->prev->next = nullptr;
            this->tail = start->prev;
        }
        else {
            start->prev->next = finish->next;
            finish->next->prev = start->prev;
        }

    }
    Iterator& operator +(int num) {
        for(int i=0; i<num)
    }

    Iterator erase(Iterator iter) {
        Node* cur = iter.getPtr();
        if (cur == head) {
            cur->next->prev = nullptr;
            head = cur->next;
        }
        else if (cur == tail) {
            cur->prev->next = nullptr;
            tail = cur->prev;
        }
        else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }

        if (cur->next != nullptr) iter.setPtr(cur->next);
        else iter.setPtr(nullptr);
        delete cur;
        size--;
        return iter;
    }



    void erase(int index) {
        if (empty() || index < 0 || index >= size) throw out_of_range("empty");
        Node* cur;
        find(cur, index);
        if (cur == head) {
            cur->next->prev = nullptr;
            head = cur->next;
        }
        else if (cur == tail) {
            cur->prev->next = nullptr;
            tail = cur->prev;
        }
        else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
        size--;
    }

private:
    void find(Node*& cur, int index) {
        if ((index + 1) < (size / 2)) {
            cur = head;
            for (int i = 0; i < index; i++) cur = cur->next;

        }
        else {
            cur = tail;
            for (int i = size - 1; i > index; i--) cur = cur->prev;
        }
    }

};

int main()
{

    MyList<int> test;

    test.push_front(5);
    test.push_front(3);
    test.push_front(4);
    test.push_back(10);
    test.push_back(11);
    test.push_back(12);
    test.push_back(13);
    //test.show();
   // test.insert_after(3, 99);

   // test.show();

    for (auto el : test) {
        cout << el << " ";
    }
    auto it = test.begin();
    test.erase(it);
    cout << endl;
    for (auto el : test) {
        cout << el << " ";
    }


}