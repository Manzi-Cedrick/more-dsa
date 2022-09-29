#include<iostream>
using namespace std;
int main()
{
    int age;
    string name;
    cout<<"Enter the name: ";
    getline(cin,name);
    cout<<"Please Enter your age: ";
    cin>>age;
    cout<<"My name is "<<name<<endl;
    cout<<"I am "<<age<<" years Old";
    return 0;


}
