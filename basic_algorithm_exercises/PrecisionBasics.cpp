#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    cout<<setw(9)<<8.25<<endl;
    cout<<setw(20)<<"Hello"<<endl;
    cout<<setprecision(2)<<fixed<<1234.56789<< endl;
    cout<<setprecision(3)<<scientific<<1234.56789<< endl;
    cout<<dec<<9<<endl;
    cout<<oct<<9<<endl;
    cout<<hex<<9<<endl;
    return 0;
}