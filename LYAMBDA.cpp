#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


class Person {
	int id;
	string name;
public:
	Person(int id,string name)  : id(id),name(name){}
	string getName() {
		return this->name;
	}
	int getId() {
		return this->id;
	}

	void print() {
		cout <<"Id is: "<<id<< " Name is: " << name<<endl;
	}

	
};


class Ammo {
	
};

class Ammo_56 : public Ammo {

};

class Ammo_56_BP : public Ammo_56 {

};

class Ammo_56_PS : public Ammo_56 {

};



class Ammo_62 : public Ammo {

};

class Ammo_62_BP : public Ammo_56 {

};

class Ammo_62_PS : public Ammo_56 {

};



class Ammo_62 : public Ammo {

};

class Ammo_62_BP : public Ammo_56 {

};

class Ammo_62_PS : public Ammo_56 {

};



int main()
{
	//int x = 10;
	//int y = 20;

	//auto add = [x, y](int a) {
	//	return (x + y)*a;
	//};
	//cout << add(5);

	/*int x = 10;
	auto increment = [&x]() {
		x++;
	}*/

											//Person p1(1, "Jack");
											//Person p2(2, "Bill");
											//Person p3(3, "Willy");
											//Person p4(4, "William");
											//Person p5(5, "James");
											//Person p6(6, "Antony");
											//Person p7(7, "Bob");
											//
											//auto multiply = [](double a, double b)-> double {
											//	return a * b;

											//};
											//vector<Person> people = { p1,p2,p3,p4,p5 };
	/*for_each(numbers.begin(), numbers.end(),
		[](int n) {
			cout << n << " ";
		}); */
	/*sort(people.begin(), people.end(), [](Person p1, Person p2) {
		return p1.getId() < p2.getId();
		});
	cout << endl << "After id sort" << endl;
	for (Person p : people) {
		p.print();
	}
	cout << endl << "After name sort" << endl;
	sort(people.begin(), people.end(), [](Person p1, Person p2) {
		return p1.getName() < p2.getName();
	});
	for (Person p : people) {
		p.print();
	}*/





	vector<int> num = {1,2,3,4,5,6,7,8,9 };
	vector<int> numChet = {};

	/*copy_if(num.begin(), num.end(), back_inserter(numChet), 
		[](int n) {
		 return n%2==0;
		});

	for (auto el : numChet) {
		cout << el << " ";
	}*/





}


