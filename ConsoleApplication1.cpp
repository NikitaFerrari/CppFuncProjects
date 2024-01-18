#include <iostream>

using namespace std;

void rectangle(int N, int K) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K ; j++) {
            cout << "* ";
        }
        cout << endl;
    }

}

void faktorial(int a, int sum) {
    for (int i = 1; i <= a; i++) {
        sum *= i;
        cout << sum << endl;
    }
}

bool simpleNumber(int a ) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
        else
            return true;

    }
    cout << endl;

}

void qubeNumber(int a) {
    cout << pow(a, 3);
}

float maxNumber(float a, float b) {
    if (a > b) return a;
    else return  b;
}

bool identifyNum(int a) {
    if (a > 0) return true;
    else return false;
}





////000


void sepeni(float a, float b, float c) {
    cout << pow(c, (a / b));
}



void summa(int min, int max, int sum) {
    if (min > max) swap(min, max);
    for (int i = min; i <= max; i++) {
        sum += i;
    }
    cout << sum;
}







int main()
{
  
    cout << "show Rectangle " << endl;
    rectangle(2, 5);
    cout << "factorial 5 " << endl;
     faktorial(5, 1);
    cout << "simple Number 121  " ;
    cout << simpleNumber(121);
    cout << endl;
    cout << "max Number 7,9  ";
    cout << maxNumber(7, 9);
    cout << endl;
    cout << "identify Number  " ;
    cout << identifyNum(7);
    cout << endl;
}