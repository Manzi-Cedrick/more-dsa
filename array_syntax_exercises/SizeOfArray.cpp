#include<iostream>
#include<array>
using namespace std;

int main()
{
    int a[10]={1,2,4,5,6,7};
    int length= sizeof(a) / sizeof(a[0]);
    cout<<"The Actual length: "<<length<<endl;
    for(int i=0;i<length;i++){
        if( a[i] != 0)
            cout<<a[i]<<endl;
    }
}