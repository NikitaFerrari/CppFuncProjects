#include <iostream>


using namespace std;


void showArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
int maxElement( int array[], int size) {
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (max < array[i]) max = array[i];
    }
    return max;
}
int minElement( int array[], int size) {
    int min = array[0];
    
    for (int i = 0; i < size; i++) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    
    return min;
}
int minIndexElement(int array[], int size) {
    int min = array[0];
    int minIndex = 0;
    for (int i = 0; i < size; i++) {
        if (min > array[i]) {
            minIndex = i;
        }
    }

    return minIndex;
}
int maxIndexElement(int array[], int size) {
    int max = array[0];
    int maxIndex = 0;
    for (int i = 0; i < size; i++) {
        if (max < array[i]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}
int summaElement(int array[], int size) {
    int summa = 0;
    for (int i = 0; i < size; i++) {
        summa += array[i];
    }
    return summa;
}
float avgElement(int array[], int size) {
    float avg = 0;
    for (int i = 0; i < size; i++) {
        avg += array[i];
    }
    avg /= size;
    return avg;
}
int massArray(int array[], int size, int array2[], int size2) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    for (int i = 0; i < size2; i++) {
        sum += array2[i];
    }
    return sum;


}
void swapMass(int array[], int size) {
    for (int i=0; i < size / 2; i++) {
        swap(array[i], array[size - 1-i]);
        
        }
   
    
}
void lolSwapMass(int array[], int array2[], int array3[], int size,int size2, int size3) {
    for (int i = 0; i < size2; i++) {
       
        swap(array[array2[i]], array[array3[i]]);
    }
}





int main()
{
    int array2[] = { 5,1,3,6 };
    int array[] = { 3,3,5,73,1,6,9,3,89 };
    int array3[] = { 1,2,3,5 };
    int size = sizeof(array) / sizeof(array[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int size3 = sizeof(array3) / sizeof(array3[0]);
    showArray(array, size);
    cout << endl;
    cout << maxElement(array, size) << " is max element";
    cout << endl;
    cout << minElement(array, size) << " is  min element";
    cout << endl;
    cout << maxIndexElement(array, size) << " is index max element";
    cout << endl;
    cout << minIndexElement(array, size) << " is index min element";
    cout << endl;
    cout << summaElement(array, size) << " is summa element";
    cout << endl;
    cout << avgElement(array, size) << " is  average element";
    cout << endl;
    cout << massArray(array, size, array2,size2) << " is  summa elementov";
    swapMass(array, size);
    showArray(array, size);
    lolSwapMass(array, array2, array3, size, size2, size3);

}

