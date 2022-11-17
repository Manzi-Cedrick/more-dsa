#include <iostream>
using namespace std;

int CalculateOperand(int num1, int num2, int n)
{
    int result;
    switch (n)
    {
    case 1:
        result = num1 + num2;
        break;
    case 2:
        result = num1 - num2;
        break;
    case 3:
        result = num1 * num2;
        break;
    case 4:
        result = num1 / num2;
        break;
    case 5:
        result = num1 % num2;
        break;
    default:
        result = 0;
        cout << "Invalid operation" << endl;
        break;
    }
    return result;
}
int main()
{
    int n;
    int num1, num2, funcResult;
    char choice;
    do{
    cout << "======================================== Welcome to the Calculator Program ====================================" << endl;
    cout << "The MENU Operations" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract " << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Modulus" << endl;
    cout << "Choose The Operation: ";
    cin >>n;
    cout << "Enter the two numbers: ";
    cin >>num1>>num2;
    funcResult = CalculateOperand(num1, num2, n);
    cout << "Result: " << funcResult << endl;
    cout << "Continue the program[N/Y]: ";
    cin>>choice;
    }
    while(choice=='Y'||choice=='y');
}
