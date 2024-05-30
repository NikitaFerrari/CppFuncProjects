#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;









class Ammo {
protected:
    int damage;
public:
    virtual int getDamage() = 0;
};

class Ammo_56 : public Ammo {

};

class Ammo_56_BP : public Ammo_56 {
public:
    Ammo_56_BP(int damage) {
        this->damage = damage;
    }
    int getDamage() { return this->damage; }
};

class Ammo_56_PS : public Ammo_56 {
public:
    Ammo_56_PS(int damage) {
        this->damage = damage;
    }
    int getDamage() { return this->damage; }
};



class Ammo_62 : public Ammo {

};

class Ammo_62_BP : public Ammo_62 {
public:
    Ammo_62_BP(int damage) {
        this->damage = damage;
    }
    int getDamage() { return this->damage; }
};

class Ammo_62_PS : public Ammo_62 {
public:
    Ammo_62_PS(int damage) {
        this->damage = damage;
    }
    int getDamage() { return this->damage; }
};



class Ammo_19 : public Ammo {

};

class Ammo_19_BP : public Ammo_19 {
public:
    Ammo_19_BP(int damage) {
        this->damage = damage;
    }
    int getDamage() { return this->damage; }

};

class Ammo_19_PS : public Ammo_19 {
public:
    Ammo_19_PS(int damage) {
        this->damage = damage;
    }
    int getDamage() { return this->damage; }
};


class Magazine {
    virtual void load() = 0;
    virtual void unload() = 0;


};

class Magazine556 : public Magazine {
    stack<Ammo_56> ammos;
};


class Magazine762 : public Magazine {

};


class Magazine919 : public Magazine {

};



int main()
{
    Ammo_56_BP ammo1(50);
    Ammo_19_BP ammo2(50);
    Ammo_62_BP ammo3(50);
    Ammo_62_PS ammo4(50);
    Ammo_56_PS ammo5(50);
    Ammo_19_PS ammo6(50);
    cout << ammo1.getDamage()<<endl;
    cout << ammo2.getDamage() << endl;
    cout << ammo3.getDamage() << endl;
    cout << ammo4.getDamage() << endl;
    cout << ammo5.getDamage() << endl;
    cout << ammo6.getDamage() << endl;
}

