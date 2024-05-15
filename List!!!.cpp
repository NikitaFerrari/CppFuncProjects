#include <iostream>
using namespace std;
template<typename T>
class MyList {
private:
	int size;
	class Node {
	public:
		T elem;
		Node* next;
		Node* prev;
		Node(const T& value) :elem(value), next(nullptr), prev(nullptr) {};
	};
	Node* head;
	Node* tail;
public:
	MyList() :head(nullptr), tail(nullptr), size(0) {};
	MyList(const MyList& otherlist) {
		if (otherlist.empty())return;
		otherlist.size = size;
		Node* ocur = otherlist.head;
		this->push_back(ocur->elem);
		for (; ocur->next != nullptr;) {
			ocur = ocur->next;
			this->push_back(ocur->elem);
		}
		this->push_back(ocur->elem);
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
	bool empty() const {
		return head == nullptr;
	}
	void pop_front() {
		if (empty()) throw out_of_range("Пусто, прямо как в твоей голове...");
		if (head->next = nullptr) {
			delete head;
			head = nullptr;
			tail = nullptr;
			size--;
		}
		else {
			Node* buf = this->head->next;
			delete this->head;
			this->head = buf;
			head->prev = nullptr;
			size--;
		}
	}
	void show() {
		Node* cur = head;
		if (empty()) throw out_of_range("Пусто, прямо как в твоей голове...");
		for (; cur->next != nullptr;) {
			cout << cur->elem << " ";
			cur = cur->next;
		}
		cout << cur->elem << endl;
	}
	void push_back(const T& value) {
		if (empty()) {
			head = new Node(value);
			tail = head;
			size++;
			return;
		}
		tail->next = newNode(value);
		tail->next->prev = tail;
		tail = tail->next;
		size++;
	}
	void pop_back() {
		if (empty()) throw out_of_range("Пусто, прямо как в твоей голове...");
		if (head->next = nullptr) {
			delete head;
			head = nullptr;
			tail = nullptr;
			size--;
		}
		else {
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
			size--;
		}
	}
	void insert_after(int index, const T& value) {
		if (empty() || index < 0 || index >= size) throw out_of_range("Пусто, прямо как в твоей голове...");
		Node* cur;
		if ((index + 1) < (size / 2)) {
			cur = head;
			for (int i = 0; i < index; i++) { cur = cur->next; }
		}
		else {
			cur = tail;
			for (int i = size - 1; i > index; i--) { cur = cur->prev; }
		}
		Node* buf = cur->next;
		cur->next = new Node(value);
		cur->next->next = buf;
		cur->next->prev = cur;
		buf->prev = cur->next;
		size++;
	}
	void emplace(int index, T& value) {
		if (empty() || index < 0) throw out_of_range("Пусто, прямо как в твоей голове...");
		Node* cur = head;
		for (int i = 0; i < index; i++)
		{
			if (cur->next == nullptr)throw out_of_range("Пусто, прямо как в твоей голове...");
		}
		cur->elem = value;
	}
	void erase(int index) {
		if (empty() || index < 0 || index >= size) throw out_of_range("Пусто, прямо как в твоей голове...");
		if ((index + 1) < (size / 2)) {
			cur = head;
			for (int i = 0; i < index; i++) { cur = cur->next; }
		}
		else {
			cur = tail;
			for (int i = size - 1; i > index; i--) { cur = cur->prev; }
		}
	}
	void clear() {
		if (empty())return;
		Node* cur = head;
		Node* buf = cur->next;
		for (; cur->next != nullptr;) {
			delete cur;
			cur = buf;
			buf = buf->next;
		}
		head = nullptr;
		size = 0;
	}
	T& front() {
		return head->elem;
	}
	T& back() {
		return tail->elem;
	}
	bool operator ==(const MyList& otherlist) {
		Node* cur = this->head;
		Node* ocur = otherlist->head;
		for (; true;) {
			if ((cur == nullptr && ocur != nullptr) ||
				(cur != nullptr && ocur == nullptr)) return 0;
			else if (cur == nullptr && ocur == nullptr)break;
			else if (cur->elem != ocur->elem)return 0;
			cur = cur->next;
			ocur = ocur->next;
		}
		return true;
	}
	bool operator !=(const MyList& otherlist) {
		return !(*this == otherlist);
	}
	MyList& operator =(const MyList& otherlist) {
		this->clear;
		if (otherlist.empty()) {
			Node* ocur = otherlist.head;
			this->size = otherlist.size;
			this->push_back(ocur->elem);
			for (; ocur->next != nullptr;) {
				ocur = ocur->next;
				this->push_back(ocur->elem);
			}
			this->push_back(ocur->elem);
		}
		return *this;
	}
	class Iterator {
	private:
		Node* ptr;
	public:
		Iterator(Node* ptr) :ptr(ptr) {}
		T& operator *() const {
			return ptr->elem;
		}
		Iterator& operator++() {
			ptr = ptr->next;
			return *this;
		}
		Iterator& operator =(const Iterator& other) {
			ptr = other.ptr;
		}
		bool operator ==(const Iterator& other) {
			return this->ptr == other.ptr;
		}
		bool operator !=(const Iterator& other) {
			return this->ptr != other.ptr;
		}
		~Iterator() {
			delete ptr;
		}
	};
	Iterator begin() {
		return Iterator(head);
	}
	Iterator end() {
		return Iterator(nullptr);
	}
	~MyList() {
		if (empty())return;
		Node* cur = head;
		Node* buf = cur->next;
		for (; cur->next != nullptr;) {
			delete cur;
			cur = buf;
			buf = buf->next;
		}
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	MyList<int> bigger;
	MyList<int> igger;
	bigger.push_front(9);
	bigger.push_front(52);
	bigger.push_front(89);
	bigger.push_front(14);
	bigger.push_front(65);
	bigger.show();
	bigger.insert_after(3, 65);
	bigger.show();
	cout << endl;
	/*igger.show();*/
	for (auto el : bigger) {
		cout << el << " ";
	}
}