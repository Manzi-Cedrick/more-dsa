#include<iostream>
using namespace std;

void duplicate(int& x,int& y,int z){
    x = x*2;
    y = y*2;
    z = z*2;
}
int main(int argc, char** argv)
{
    int x=5,y=7,z=8;
    duplicate(x,y,z);
    cout<<"The duplicate : "<<"x : "<<x<<"y : "<<y<<"z: "<<z<<endl;
    return 0;
}