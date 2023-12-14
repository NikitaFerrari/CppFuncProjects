#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int main()
{
    srand(time(NULL));
    const int SIZE = 100;
    int begin = 0;
    int iterazz = 0;
    int min = 10;
    int max = 100;
    int end = SIZE;
     int array1[SIZE] = {};
     int bubiterazz = 0;
     cout << "bubble sort: " << endl;
     for (int i = 0; i < SIZE; i++) {
         array1[i] = min + rand() % (max - min);
        
     }
     bool hhh = true;
     for (int i = 0; i <= SIZE-1; i++) {
         for (int j = 0; j < SIZE - 1-i; j++) {
             bubiterazz++;
             if (array1[j] > array1[j + 1]) {
                 swap(array1[j], array1[j + 1]);
                 hhh = false;
             }


             

         }
         if (hhh == true) break;
         
     }
     Sleep(1000);
     cout << " bubble sort complited: " << endl;
     Sleep(1000);
     cout << " start insertions sort:" << endl;
     int insertioniteraz = 0;
     int array2[SIZE] = {};
         for (int i = 0; i < SIZE; i++) {                               
             array2[i] = min + rand() % (max - min);
            
         }
         
         for (int i = 1; i < SIZE; i++) {
             for (int j = i; j >0; j--) {
                 insertioniteraz++;
                 if (array2[j] < array2[j - 1]) {
                     swap(array2[j], array2[j - 1]);
                 }
                 else break;
                 
             }


         }
        
         
         Sleep(1000);
         cout << "insertions sort complited : " << endl;
         Sleep(1000);
         cout << " start shaker sort: " << endl;
    int array[SIZE] = { };
    for (int i = 0; i < SIZE; i++) {
        array[i] = min + rand() % (max - min);
        
    }
 
    bool hh = true;
    for (int begin = 0; begin < end;) {
        for (int j = begin ; j < end - 1; j++) {

            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                hh = false;
            }

            iterazz++;

            

        }
        if (hh == true) {
            break;
        }
        end--;
      
        hh = true;
        for (int j = end-1; j > begin; j--) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
                hh = false;
                iterazz++;
            }
        }

        if (hh == true) {
            break;
        }
        begin++;
        
       
        
    }
    Sleep(1000);
    cout << "shaker sort complited: " << endl;
    Sleep(1000);
    cout << endl << "bubble sort(count of iterations): " << bubiterazz << endl;
    cout << endl << "insertion sort(count of iterations): " << insertioniteraz << endl;
    cout << endl << " shaker sort(count of iterations): " << iterazz << endl;
}




