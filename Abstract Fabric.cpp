#include <iostream>
#include <string>
using namespace std;




class Axe  {
public:
	virtual void hitting() = 0;
	virtual ~Axe() = default;
};

class DaneAxe : public Axe {
	
public:
	
	void hitting() {
		cout << "Danish Axe Hit!" << endl;
	}
};

class Masacari : public Axe {
	
public:
	
	void hitting() {
		cout << "Japan Hit" << endl;
	}
};

class PoleAxe : public Axe {
	
public:
	
	void hitting() {
		cout << "European Hit" << endl;
	}
};





class Sword {
public:
	virtual void swinging() = 0;
	virtual ~Sword() = default;

};

class Sax : public Sword {

public:
	

	void swinging() {
		cout << "Norvegial Kiy YA!" << endl;
	}
};

class Katana : public Sword {
	
public:
	
	void swinging() {
		cout << "Japan Swing" << endl;
	}
};

class BroadSword : public Sword {
	
public:
	
	void swinging() {
		cout << "УЕБУ ЩАС" << endl;
	}
};






class Spear {
public:
	virtual void thrusting()=0;
	virtual ~Spear() = default;
};

class Gungnir : public Spear {
	
public:
	
	void thrusting() {
		cout << "Norvean Hit копьём" << endl;
	}
};

class Yari : public Spear {
	
public:
	
	void thrusting() {
		cout << "Japan ThrustС" << endl;
	}
};

class Pilum : public Spear {
	
public:
	
	void thrusting() {
		cout << "European Thrust" << endl;
	}
};



class BlackSmith {
public:
	virtual Axe* createAxe()=0;
	virtual Sword* createSword()=0;
	virtual Spear* createSpear()=0;
	virtual ~BlackSmith() = default;



};



class NorvegianBlackSmith : public BlackSmith {
public:
	Axe* createAxe() {
		return new DaneAxe();
	}
	Sword* createSword() {
		return new Sax();
	}
	Spear* createSpear() {
		return new Gungnir();
	}



};

class EuropeanBlackSmith : public BlackSmith {
public:
	Axe* createAxe() {
		return new PoleAxe();
	}
	Sword* createSword() {
		return new BroadSword();
	}
	Spear* createSpear() {
		return new Pilum();
	}



};


class JapanBlackSmith : public BlackSmith {
public:
	Axe* createAxe() {
		return new Masacari();
	}
	Sword* createSword() {
		return new Katana();
	}
	Spear* createSpear() {
		return new Yari();
	}



};




int main()
{
	BlackSmith* bl1 = new JapanBlackSmith();
	bl1->createSword()->swinging();
}
