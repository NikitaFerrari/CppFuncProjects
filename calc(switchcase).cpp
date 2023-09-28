

#include <iostream>
using namespace std;
int main()
{
    float num, num1;
    char operation;
    cin >> num>>num1;
    cin >> operation;
    switch (operation) {
    case '+':
        cout << num + num1;
        break;
    case '-':
        cout << num - num1;
        break;
    case '*':
        cout << num * num1;
        break;
    case '/':
        cout << num / num1;
        break;
    default:
        cout << "tak nizya";


    }
    if (num == 0 )
        cout << "zero nolzya";
    else
        cout << " vi maladec";

    

        
        

}
    
    










