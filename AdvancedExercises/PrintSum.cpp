#include<iostream>
using namespace std;
double SumOutput(double num1,double num2){
    double sum = num1+num2;
    return sum;
}
int main(){
    double num1,num2;
    cout << "======================================== Welcome to the Addition Program ====================================" << endl;
    cout<<"Enter the two numbers: ";
    cin >> num1 >> num2;
    cout<<"The sum of the "<<num1<<" and "<<num2<<" numbers is: "<<SumOutput(num1,num2);
    return 0;
}