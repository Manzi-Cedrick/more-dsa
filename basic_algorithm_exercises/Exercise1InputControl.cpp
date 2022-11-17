#include<iostream>
using namespace std;

int main()
{
    string firstname;
    string lastname;
    string age;
    cout<<"Enter the firstName: ";
    getline(cin,firstname);
    cout<<"Enter the lastName: ";
    getline(cin,lastname);
    cout<<"Please Enter your age: ";
    cin>>age;
    cout<<firstname<<lastname<<age;
    return 0;
}
