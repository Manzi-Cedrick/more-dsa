#include<iostream>
using namespace std;

int fibonnaci (int n) {
    if( n ==0 ) return 0;
    if( n == 1) return 1;
    int sum = fibonnaci(n-1)  + fibonnaci(n-2);
    return sum;
}
int main() {
    cout<<fibonnaci(5);
    return 0;
}