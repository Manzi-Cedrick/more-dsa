#include <iostream>
using namespace std;
int main()
{
    int a = 12;
    int b = 25;
    // And Bitwise Operator is used to conduct a comparison operation between the bits of a byte 
    // It Shifts bits into byte
    cout << (a&b)<<endl;
    // Or Bitwise Operator 
    cout << (a|b)<<endl;
    // X Or Bitwise Operator gives the opposite of the and real values;
    cout << (a^b)<<endl;
    // Not Bitwise Operator
    cout << (~a)<<endl;
    // Bitwise left shift operator
    cout << (a << 1)<<endl;
    cout << (a << 2)<<endl;
    cout << (a << 3)<<endl;
    // Bitwise right shift operator
    cout << (b >> 1)<<endl;
    cout << (b >> 2)<<endl;
    cout << (b >> 3)<<endl;
    return 0;
}