#include <iostream>
#include <fstream>
#include <string>
using namespace std;



void foo(string path) {
	ifstream in(path);
	string str;
	if(in.is_open()) {
		while (getline(in, str)) {
			cout << str << endl;
		}
	}
	in.close();

}



void writeFile(string path) {
	ofstream out(path, ios::app);
	if (out.is_open()) {
		for(int i=0; i<500; i++)
		out <<i+1<< ". Love Some Baby" << endl;
	}

	out.close();
}

void foon(int num) {
	if (num < 0) {
		throw 5;
	}
	cout << num << "ok."<< endl;
}





int main()
{
	setlocale(LC_ALL, "rus");
	
	try {
		foon(-5);

	}
	catch (int) {
		cout << "число меньше 0" << endl;
	}


	/*writeFile("EGOR.txt");
	foo("EGOR.txt");*/

}
