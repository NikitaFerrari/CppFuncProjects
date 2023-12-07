#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    const int SIZE = 10;
    int array[SIZE] = { };
    int minRange;
    int maxRange;
    cout << "min" << endl;
    int maxIndex = 0;
    int minIndex = 0;
    cin >> minRange;
    cout << "max" << endl;
    cin >> maxRange;
    for (int i = 0; i < SIZE; i++) {
        array[i] = minRange + rand() % (maxRange - 1 + minRange);
        cout << array[i] << endl;

    }
    int max = array[0];
    int min = array[0];
    for (int i = 0; i < SIZE; i++) {
        if (max < array[i]) {
            max = array[i];
            maxIndex = i;
        }
        if (min > array[i]) {
            min = array[i];
            minIndex = i;
        }
    }
    cout << "index max number==" << maxIndex << endl;
    cout << "index min number==" << minIndex << endl;
    cout << "max number=="<<max <<endl;
    cout << "min number==" << min << endl;
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];

    }
    cout <<"summa chisel"<< sum << endl;
    float srednAri = sum/SIZE;
    cout << "sredn arifmet" << (float)srednAri << endl;



}
