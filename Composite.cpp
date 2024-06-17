#include <iostream>
#include <vector>
using namespace std;

class FileSystem {
public:
	virtual ~FileSystem() = default;
	virtual void add(FileSystem* component) = 0;
	virtual void remove(string name) = 0;
	virtual float getWeight() = 0;

};

class File : public FileSystem {
private:
	float weight;
	string name;
public:
	File(float weight, string name) :  weight(weight), name(name){}
	
	float getWeight() {
		return weight;
	}

	void display() {
		cout << "Name: " << name << endl << "Weight: " << weight << endl;
	}

	void add(FileSystem* component) {
		throw logic_error("Operatiron not supported");
	}

	void remove(string name) {
		throw logic_error("Operatiron not supported");
	}

};

class Directory :public FileSystem {
private:
	string name;
	vector <FileSystem*> components;
public:
	Directory(string name) : name(name){}
	~Directory() {
		for (auto component : components) {
			delete component;
		}
	}

	void add(FileSystem* component) {
		components.push_back(component);
	}

	void display() {
		cout << "Name: " << name << endl;
		cout << "Weight: " << getWeight() << endl;
	}

	float getWeight() {
		float result = 0;
		for (auto component : components) {
			result += component->getWeight();
		}
		return result;
	}
	void remove(string name) {
		cout << "gffdghdf";
	}

};


int main()
{

	Directory* d1 = new Directory("D1");
	File* f1 = new File(103.53,"F1");
	File* f2 = new File(120.53, "F2");
	File* f3 = new File(1420.63, "F3");
	d1->add(f1);
	d1->add(f2);
	d1->add(f3);
	Directory* d2 = new Directory("D2");
	File* f4 = new File(130.343, "F4");
	File* f5 = new File(10342.3, "F5");
	d2->add(f4);
	d2->add(f5);
	Directory* d3 = new Directory("D3");
	File* f6 = new File(1023.3, "F6");
	File* f7 = new File(140.3, "F7");
	d3->add(f6);
	d3->add(f7);
	d3->add(d1);
	d3->add(d2);
	Directory* d4 = new Directory("D4");
	File* f8 = new File(1023.3, "F8");
	d4->add(d3);
	d4->add(f8);
   
	d4->display();
}

