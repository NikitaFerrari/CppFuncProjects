#include <iostream>
using namespace std;


class Sword {
public:
    virtual void attack() = 0;
    virtual ~Sword() = default;
};

class Katana : public Sword {
public:
    void attack() override {
        cout << "AAA Kata.."<<endl;

    }
};

class BroadSword : public Sword {
public:
    void attack() override {
        cout << "Swing by brsw" << endl;

    }
};


class Ulfbert : public Sword {
public:
    void attack() override {
        cout << "Swing by ulfbrt" << endl;

    }
};


class Blacksmith {
public:
    virtual Sword* createSword() = 0;
    virtual ~Blacksmith() = default;
};

class JapaneseBlacksmith : public Blacksmith {
public:
    Sword* createSword() override {
        return new Katana();
    }
};

class EuropeanBlacksmith : public Blacksmith {
public:
    Sword* createSword() override {
        return new BroadSword();
    }
};

class SkandinavianBlacksmith : public Blacksmith {
public:
    Sword* createSword() override {
        return new Ulfbert();
    }
};



int main()
{
    
    string country = "Skandinavian";
    Blacksmith* someBlacksmith=nullptr;
    if (country == "Japanese") {
        someBlacksmith = new JapaneseBlacksmith();
    }
    else if (country == "Europa") {
        someBlacksmith = new EuropeanBlacksmith();
    }
    else if (country == "Skandinavian") {
        someBlacksmith = new SkandinavianBlacksmith();
    }
    if (someBlacksmith != nullptr) {
        someBlacksmith->createSword()->attack();
    }

   

}

