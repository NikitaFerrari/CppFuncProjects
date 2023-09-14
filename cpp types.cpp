

#include <iostream>
using namespace std;
int main()
{
    short shortik = SHRT_MIN;
    short shortik1 = SHRT_MAX;
    int inter = INT32_MIN;
    int inter1 = INT32_MAX;
    long long Longer = LLONG_MIN;
    long long Longer1 = LLONG_MAX;
    unsigned short Uni = 0;
    unsigned short Uni1 = USHRT_MAX;
    unsigned int  Uinti = 0;
    unsigned int Uinti1 = UINT32_MAX;
    unsigned long long Ulongi = 0;
    unsigned long long Ulongi1 = ULLONG_MAX;
    float Fli = FLT_MIN;
    float Fli1 = FLT_MAX;
    double Duod = DBL_MIN;
    double Duod1 = DBL_MAX;
    bool Ball = 0;
    bool Ball1 = 1;
    char Chair = 0;
    char Chair1 = 255;
    cout << "type \t\t\t| byte \t\t| min \t\t\t| max" <<endl;
    cout << "short\t\t\t|" << sizeof(short) << "\t\t|"  << shortik << "\t\t\t|" << shortik1 << endl;
    cout << "int\t\t\t|" << sizeof(int) << "\t\t|" << inter << "\t\t|" << inter1 << endl;
    cout << "long long\t\t|" << sizeof(long long) << "\t\t|" << Longer << "\t|" << Longer1 << endl;
    cout << "unsigned short\t\t|" << sizeof(unsigned short) << "\t\t|" << Uni << "\t\t\t|" << Uni1 << endl;
    cout << "unsigned int\t\t|" << sizeof(unsigned int) << "\t\t|" << Uinti << "\t\t\t|" << Uinti1 << endl;
    cout << "unsigned long long\t|" << sizeof(unsigned long long) << "\t\t|" << Ulongi << "\t\t\t|" << Ulongi1 << endl;
    cout << "float\t\t\t|" << sizeof(float) << "\t\t|" << Fli << "\t\t|" << Fli1 << endl;
    cout << "double\t\t\t|" << sizeof(double) << "\t\t|" << Duod << "\t\t|" << Duod1 << endl;
    cout << "bool\t\t\t|" << sizeof(bool) << "\t\t|" << Ball << "\t\t\t|" << Ball1 << endl;
    cout << "char\t\t\t|" << sizeof(char) << "\t\t|" << Chair << "\t\t\t|" << Chair1 << endl;



   
    
}



