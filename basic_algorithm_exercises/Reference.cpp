#include<iostream>
using namespace std;
int main(int argc, char** argv){
    int x =10;
    int& ref =x;
    x=15;
    cout<<"The reference: "<<ref<<endl;
    cout<<"The x: "<<x<<endl;
    return 0;
}