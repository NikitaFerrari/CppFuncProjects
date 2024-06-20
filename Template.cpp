#include <iostream>
using namespace std;


class Coffee {
public:
	
	void prepareRecipe() {
		boilWater();
		brewCoffee();
		pourInCup();
		addCondiments();

	}

protected:
	void boilWater() {
		cout << "Boiling Water" << endl;
	}

	void pourInCup() {
		cout << "Pour into cup" << endl;
	}

	virtual void brewCoffee()=0;

	virtual void addCondiments() = 0;

};


class BlackCoffee : public Coffee{
protected:
	void brewCoffee() override {
		cout << "Driping coffee through filter" << endl;
	}

	void addCondiments() override {
		cout << "No condiments" << endl;
	}

};


class Latte : public Coffee {
protected:
	void brewCoffee() override {
		cout << "Making espresso " << endl;
	}

	void addCondiments() override {
		cout << "Adding steamed milk" << endl;
	}

};



int main()
{
	Coffee* blackCoffee = new BlackCoffee();

	Coffee* latte = new Latte();



	latte->prepareRecipe();
}

