#include<iostream>
using namespace std;

int sumDigit(int n)
{
    if(n==0) return 0;
    int smallSum = sumDigit(n/10);
    return n%10 + smallSum;
}
int main()
{
    int n;
    cout << "Enter a numeral: ";
    cin>>n;
    cout<<sumDigit(n);
    return 0;
}