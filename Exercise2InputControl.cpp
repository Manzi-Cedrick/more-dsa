#include<iostream>
using namespace std;

int main()
{
    string fullname;
    float amount;
    float interestRate;
    int PaymentTime;
    double Interest;

    cout<<"Enter your names: ";
    cin.ignore();
    getline(cin,fullname);
    cout<<"Enter the amount : ";
    cin>>amount;
    cout<<"Enter the interest rate value: ";
    cin>>interestRate;
    cout<<"Enter the Payment Duration: ";
    cin>>PaymentTime;

    Interest= (PaymentTime*interestRate*amount) / 100;
    cout<<"The Final Interest on the amount is :"<<Interest<<endl;

    return 0;
}
