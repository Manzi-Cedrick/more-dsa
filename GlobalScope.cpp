#include<iostream>
using namespace std;

namespace finance{
    int amount=25;
}
int amount = 15;

int main()
{
    int amount = 12;
    cout<<"The Local Amount is: "<<amount<<endl;
    cout<<"The Global Amount is: "<<::amount<<endl;
    cout<<"The amount from fn is:"<<finance::amount<<endl;
    return 0;
}
