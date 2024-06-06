#include <iostream>
#include <string>
using namespace std;


class Burger {
public:
	int beaf;
	bool salate;
	bool picules;
	bool tomato;
	bool Upperbun;
	bool Downbun;
	bool mustard;
	bool burgerSouce;
	bool mayo;
	bool ketchup;
	int becon;
	int cheese;

	void show() {
		cout << "beaf: " << beaf << endl << "salate: " << salate << endl << "picules: " << picules << endl << "tomato: " << tomato << endl << "Upperbun: " << Upperbun << endl << "Downbun: " << Downbun << endl << "mustard: " << mustard << endl << "burgerSouce: " << burgerSouce << endl << "mayo: " << mayo << endl << "ketchup: " << ketchup << endl << "becon: " << becon << endl << "cheese: " << cheese << endl;
	}




};







class Coocker {
private:
	Burger* result;
public:

	Coocker() {}
	~Coocker() {
		delete result;
	}

	Coocker& reset() {
		this->result = new Burger();
		return *this;
	}

	Coocker& setBeaf(int beaf) {
		this->result->beaf = beaf;
		return *this;
	}

	Coocker& setSalate(bool salate) {
		this->result->salate = salate;
		return *this;
	}

	Coocker& setPucules(bool picules) {
		this->result->picules = picules;
		return *this;
	}

	Coocker& setTomato(bool tomato) {
		this->result->tomato = tomato;
		return *this;
	}

	Coocker& setUpperbun(bool Upperbun) {
		this->result->Upperbun = Upperbun;
		return *this;
	}

	Coocker& setDownbun(bool Downbun) {
		this->result->Downbun = Downbun;
		return *this;
	}

	Coocker& setMustard(bool mustard) {
		this->result->mustard = mustard;
		return *this;
	}

	Coocker& setBurgerSouce(bool burgerSouce) {
		this->result->burgerSouce = burgerSouce;
		return *this;
	}

	Coocker& setMayo(bool mayo) {
		this->result->mayo = mayo;
		return *this;
	}

	Coocker& setKetchup(bool ketchup) {
		this->result->ketchup = ketchup;
		return *this;
	}

	Coocker& setBecon(int becon) {
		this->result->becon = becon;
		return *this;
	}

	Coocker& setCheese(int cheese) {
		this->result->cheese = cheese;
		return *this;
	}

	Burger* getResult() {
		return this->result;
	}
};


class Administrator {
private:
	Coocker povar;
public:

	Burger* setCheeseBurger() {
		povar.reset();
		povar.setDownbun(true).setUpperbun(true).setBeaf(2).setKetchup(true).setCheese(2).setTomato(true);
		return povar.getResult();
	}

	Burger* setCeapBurger() {
		povar.reset();
		povar.setDownbun(true).setUpperbun(true).setSalate(true);
		return povar.getResult();
	}

	Burger* setRichBurger() {
		povar.reset();
		povar.setDownbun(true).setUpperbun(true).setBeaf(3).setBurgerSouce(true).setBecon(2).setPucules(true).setMustard(true).setCheese(5);
		return povar.getResult();
	}

};






int main()
{
	Administrator a;
	a.setRichBurger()->show();

  
}
