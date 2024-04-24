#include <iostream>
using namespace std;


template <typename T> 
class MyList {
private:
	T* array;
	int capacity=10;
	int size=0;
public:
	MyList() {
		this->array = new T[capacity];
	}

	T& front() {
		return array[0];
	}
	T& back() {
		return array[size-1];
	}

	bool empty() {
		if (size > 0) return false;
		else return true;
	}

	int getSize() {
		return size;
	}
	
	void pushBack(T el) {
		increaseList();
		this->array[this->size++] = el;
	}
	
	void pushFront(T el) {
		increaseList();
		this->insert(0, el);
	}

	void clear() {
		this->capacity = 10;
		this->size = 0;
		
		delete[] array;
		array = new int[capacity];
		
	}

	void pop(int index) {
		if (index >= size || index < 0) return;
		for (int i = index; i < size; i++) {
			array[i] = array[i + 1];
		}
		size--;
	}

	void insert(T el, int index) {
		if (index >= size || index < 0) return;
		for (int i = size; i > index; i--) {
			array[i] = array[i - 1];
		}
		array[index] = el;
		size++;
	}

	~MyList() {
		delete[] array;
	}

	void set(int index, T el) {
		if (index >= size || index < 0) return;
		array[index] = el;
	}

	int max_size() {
		return INT_MAX;
	}

	void show() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}

	void insertRange(int index, T* arr, int size2) {
		
		if (index >= size || index < 0) return;
		increaseList(size2);
		for (int i = size; i >= index; i--) {
			array[i + size2] = array[i];
		}
		for (int i = 0; i < size2; i++) {
			array[index+i] = arr[i];
		}
		size+=size2;
	}

	void popBack() {
		size--;
	}

	void popFront() {
		pop(0);
	}


private:

	void increaseList(int count =1) {
		if ((this->size + count) >= this->capacity * 0.75) {
			this->capacity *= 1.5;
			if (capacity < size + count) this->capacity += count;
			T* buf = new T[this->capacity];
			for (int i = 0; i < size; i++)
			{
				buf[i] = array[i];
			}
			delete[] array;
			array = buf;
		}
	}

};

int main()
{
	int* arr = new int[]{5,5,5,4,4,4,43,4,423,32,23,23,3,2,3,32,32,32,32,3};
	int size3 = _msize(arr) / sizeof(arr[0]);
	

	MyList<int> list;
	list.pushBack(1);
	list.pushBack(3);
	list.pushBack(4);
	list.pushBack(5);
	list.show();
	list.insert(2, 1);
	list.show();
	list.insertRange(2, arr, size3);
	list.show();
}
